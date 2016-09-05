#include "QMyMap.h"
#include "QMySunShine.h"

QMyMap::QMyMap(QGameMode *parent)
	:QMyObject(parent)
{
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 5; j++)
		{
			isPlantedMap[i][j] = false;
			objectPointMap[i][j] = NULL;
		}
	MapRect.setX(245);
	MapRect.setY(87);
	MapRect.setWidth(1003);
	MapRect.setHeight(503);

	for (int i = 0; i < 12; i++)
	{
		verticalLines[i] = MapRect.x() + MapRect.width() / 12 * i;
		if (i < 5)
		{
			horizontalLines[i] = MapRect.y() + MapRect.height() / 5 * i;
		}
	}
	ReadytoPlant = new QItemShade;
	ReadytoPlant_Shadow = new QItemShade;
	ReadytoPlant_Shadow->setParentItem(this);
	ReadytoPlant->setParentItem(this);
	ReadytoPlant->setVisible(false);
	ReadytoPlant_Shadow->setVisible(false);
	ReadytoPlant_Shadow->setOpacity(0.7);
	connect(ReadytoPlant, SIGNAL(leftButtonClicked()), this, SLOT(Plantrequest_Try()));
	connect(ReadytoPlant, SIGNAL(rightButtonClicked()), this, SLOT(Plantrequest_Cancelled()));
	connect(ReadytoPlant, SIGNAL(cursorMoved(QPointF)), this, SLOT(Plantrequest_Update(QPointF)));
}

QMyMap::~QMyMap()
{

}

//public slots
void QMyMap::Plantrequest_Ready(objectNames itemname, QPointF itemPos)
{
	ReadytoPlant->setVisible(true);
	QRectF Pixbounding = ReadytoPlant->boundingRect();
	changePixmap(itemname);
	ReadytoPlant->setPos(itemPos.x() - (Pixbounding.width() / 2), itemPos.y() - (Pixbounding.height() / 2));
	ReadytoPlant->grabMouse();
}

void QMyMap::Plantrequest_Update(QPointF itemPos)
{
	if (!MapRect.contains(itemPos))
	{
		ReadytoPlant_Shadow->setVisible(false);
	}
	else
	{
		QPoint tempPoint = PostoPoint(itemPos);
		int x = tempPoint.x();
		int y = tempPoint.y();
		if ((isPlantedMap[x][y] == true) || (x >= 9))
		{
			ReadytoPlant_Shadow->setVisible(false);
		}
		else
		{
			ReadytoPlant_Shadow->setPointinMap(tempPoint);
			QPointF tempPos;
			tempPos = PointtoPos(tempPoint);
			QRectF tempRect = ReadytoPlant_Shadow->boundingRect();
			tempPos.setX(tempPos.x() + (MapRect.width() / 12 - tempRect.width()) / 2);
			tempPos.setY(tempPos.y() + (MapRect.height() / 5) - 27 - tempRect.height());
			ReadytoPlant_Shadow->setPos(tempPos);
			ReadytoPlant_Shadow->setVisible(true);
		}
	}
}

void QMyMap::Plantrequest_Try()
{
	if (ReadytoPlant_Shadow->isVisible())
	{
		pointNewItemtoPlantOn = ReadytoPlant_Shadow->getPointinMap();
		emit addItem(ReadytoPlant->objectTypeNames, ReadytoPlant_Shadow->scenePos());
		Plantrequest_Done();
	}
	else
	{
		QPointF tempPos;
		tempPos.setX(ReadytoPlant->pos().x() + boundingRect().width() / 2);
		tempPos.setY(ReadytoPlant->pos().y() + boundingRect().height() / 2);
		if (!MapRect.contains(tempPos))
			Plantrequest_Cancelled();
	}
}

void QMyMap::Plantrequest_Done()
{
	ReadytoPlant->setVisible(false);
	ReadytoPlant_Shadow->setVisible(false);
	ReadytoPlant->setPos(900, 600);
	ReadytoPlant_Shadow->setPos(900, 600);
	emit RequestDone();
}

void QMyMap::Plantrequest_Cancelled()
{
	ReadytoPlant->setVisible(false);
	ReadytoPlant_Shadow->setVisible(false);
	ReadytoPlant->setPos(900, 600);
	ReadytoPlant_Shadow->setPos(900, 600);
	emit RequestCancelled();
}

void QMyMap::Itemadded(QMyObject* newItemAdded)
{
	if (newItemAdded->getType() == Plants)
	{
		QPlants* newPlanttoLoad = (QPlants*)newItemAdded;
		int x = pointNewItemtoPlantOn.x();
		int y = pointNewItemtoPlantOn.y();
		isPlantedMap[x][y] = true;
		objectPointMap[x][y] = newItemAdded;
		newPlanttoLoad->setZValue(y);
		newPlanttoLoad->setPointinMap(x, y);
		PlantsinMap.push_back(newPlanttoLoad);
		connect(newPlanttoLoad, SIGNAL(addtomap(objectType, QMyObject*)), this, SLOT(addtoMap(objectType, QMyObject*)));
		connect(newPlanttoLoad, SIGNAL(removefrommap(objectType, QMyObject*)), this, SLOT(removefromMap(objectType, QMyObject*)));
	}
	else if (newItemAdded->getType() == Zombies)
	{
		QPointF tempPos = newItemAdded->pos();
		tempPos.setX(tempPos.x() + (MapRect.width() / 12 - newItemAdded->boundingRect().width()) / 2);
		tempPos.setY(tempPos.y() + MapRect.height() / 5 - newItemAdded->boundingRect().height() - 27);
		newItemAdded->setPos(tempPos);
		tempPos.setX(tempPos.x() + newItemAdded->boundingRect().width() / 2);
		tempPos.setY(tempPos.y() + newItemAdded->boundingRect().height() - 27);
		newItemAdded->setPointinMap(PostoPoint(tempPos));
		newItemAdded->setZValue(newItemAdded->getPointinMap().y());
		ZombiesinMap.push_back((QZombies*)newItemAdded);
		connect(newItemAdded, SIGNAL(removefrommap(objectType, QMyObject*)), this, SLOT(removefromMap(objectType, QMyObject*)));
	}
}

void QMyMap::addtoMap(objectType mytypename, QMyObject* myobject)
{
	switch (mytypename)
	{
	case Zombies:
	{
		PlantsinMap.push_back((QPlants*)myobject);
	}
	break;
	case Weapons:
	{
		WeaponsinMap.push_back((QWeapons*)myobject);
		scene()->addItem(myobject);
		myobject->setPointinMap(PostoPoint(myobject->pos()));
		myobject->setZValue(myobject->getPointinMap().y());
		connect(myobject, SIGNAL(removefrommap(objectType, QMyObject*)), this, SLOT(removefromMap(objectType, QMyObject*)));
	}
	break;
	case SunShine:
	{
		QMySunShine* newSunShine = (QMySunShine*)myobject;
		connect(newSunShine, SIGNAL(BeTaken()), this, SIGNAL(SunShineAdded()));
	}
	break;
	default:
		break;
	}
}

void QMyMap::removefromMap(objectType mytypename, QMyObject* myobject)
{
	switch (mytypename)
	{
	case Plants:
	{
		PlantsinMap.removeAll((QPlants*)myobject);
		QPoint tempPoint = myobject->getPointinMap();
		isPlantedMap[tempPoint.x()][tempPoint.y()] = false;
		objectPointMap[tempPoint.x()][tempPoint.y()] = NULL;
	}
	break;
	case Zombies:
	{
		ZombiesinMap.removeAll((QZombies*)myobject);
	}
	break;
	case Weapons:
	{
		WeaponsinMap.removeAll((QWeapons*)myobject);
	}
	break;
	default:
		break;
	}
}

void QMyMap::ShovelMessage(QPointF shovelPoint)
{
	QPoint tempPoint = PostoPoint(shovelPoint);
	if (objectPointMap[tempPoint.x()][tempPoint.y()] != NULL)
	{
		objectPointMap[tempPoint.x()][tempPoint.y()]->setHP(-1);
	}
}

//public
void QMyMap::changePixmap(objectNames itemname)
{
	switch (itemname)
	{
	case PeaShooter:
	{
		ReadytoPlant->objectTypeNames = itemname;
		ReadytoPlant_Shadow->objectTypeNames = itemname;
		ReadytoPlant->LoadPixmap("Resources/pvz-material/images/Plants/Peashooter/0.gif");
		ReadytoPlant_Shadow->LoadPixmap("Resources/pvz-material/images/Plants/Peashooter/0.gif");
	}
	break;
	case SunFlower:
	{
		ReadytoPlant->objectTypeNames = itemname;
		ReadytoPlant_Shadow->objectTypeNames = itemname;
		ReadytoPlant->LoadPixmap("Resources/pvz-material/images/Plants/SunFlower/0.gif");
		ReadytoPlant_Shadow->LoadPixmap("Resources/pvz-material/images/Plants/SunFlower/0.gif");
	}
	break;
	case WallNut:
	{
		ReadytoPlant->objectTypeNames = itemname;
		ReadytoPlant_Shadow->objectTypeNames = itemname;
		ReadytoPlant->LoadPixmap("Resources/pvz-material/images/Plants/WallNut/0.gif");
		ReadytoPlant_Shadow->LoadPixmap("Resources/pvz-material/images/Plants/WallNut/0.gif");
	}
	break;
	default:
		break;
	}
}

void QMyMap::timerEvent(QTimerEvent *event)
{
	examineMap();
}

void QMyMap::examineMap()
{
	for (const auto &i : PlantsinMap)
	{
		{
			i->setThreatend(false);
			for (const auto &j : ZombiesinMap)
			{
				if (i->inRange(j))
				{
					i->setThreatend(true);
					break;
				}
			}
		}
	}
	for (const auto &i : ZombiesinMap)
	{
		i->setExcited(false);
		for (const auto &j : PlantsinMap)
		{
			if (i->inRange(j))
			{
				i->setExcited(true);
				i->setEnemy(j);
				break;
			}
		}
		QPointF tempPointf;
		tempPointf.setX(i->pos().x() + i->boundingRect().width() / 2);
		tempPointf.setY(i->pos().y() + i->boundingRect().height());
		i->setPointinMap(PostoPoint(tempPointf));
	}
	for (const auto &i : WeaponsinMap)
	{
		for (const auto &j : ZombiesinMap)
		{
			if (i->inRange(j))
			{
				i->setIsExcited(true, j);
				break;
			}
		}
		i->setPointinMap(PostoPoint(i->pos()));
	}

}

qreal QMyMap::getVerticalLine(int i)
{
	return verticalLines[i];
}

qreal QMyMap::getHorizontalLine(int i)
{
	return horizontalLines[i];
}

QPoint QMyMap::PostoPoint(QPointF itemPos)
{
	QPoint tempPoint;
	for (int i = 0; i < 12; i++)
	{
		if (i == 11)
		{
			tempPoint.setX(11);
		}
		else if ((itemPos.x() >= verticalLines[i]) && (itemPos.x() < verticalLines[i + 1]))
		{
			tempPoint.setX(i);
			break;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		if (i == 4)
		{
			tempPoint.setY(4);
		}
		else if ((itemPos.y() >= horizontalLines[i]) && (itemPos.y() < horizontalLines[i + 1]))
		{
			tempPoint.setY(i);
			break;
		}
	}
	return tempPoint;
}

QPointF QMyMap::PointtoPos(QPoint itemPoint)
{
	QPointF tempPointF;
	tempPointF.setX(verticalLines[itemPoint.x()]);
	tempPointF.setY(horizontalLines[itemPoint.y()]);
	return tempPointF;
}

QRectF QMyMap::getRect()
{
	return MapRect;
}






