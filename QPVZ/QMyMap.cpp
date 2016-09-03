#include "QMyMap.h"
#include "qdebug.h"

QMyMap::QMyMap(QWidget *parent)
{
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 9; j++)
		{
			Map[i][j] = NULL;
			isPlantedMap[i][j] = false;
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
			QStatusString.setPlainText(QStatusString.toPlainText() + "\n" + QString::number((int)horizontalLines[i], 10));

		}
	}
	ReadytoPlant = new QItemShade;
	ReadytoPlant_Shadow = new QItemShade;
	ReadytoPlant_Shadow->setParentItem(this);
	ReadytoPlant->setParentItem(this);
	ReadytoPlant->setVisible(false);
	ReadytoPlant_Shadow->setVisible(false);
	ReadytoPlant_Shadow->setOpacity(0.7);
	QStatusString.setParentItem(this);
	QStatusString.setPos(400, 300);
	connect(ReadytoPlant, SIGNAL(leftButtonClicked()), this, SLOT(Plantrequest_Try()));
	connect(ReadytoPlant, SIGNAL(rightButtonClicked()), this, SLOT(Plantrequest_Done()));
	connect(ReadytoPlant, SIGNAL(cursorMoved(QPointF)), this, SLOT(Plantrequest_Update(QPointF)));
}

QMyMap::~QMyMap()
{
	delete ReadytoPlant;
	delete ReadytoPlant_Shadow;
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

//void QMyMap::setScene(QGraphicsScene* Modescene)
//{
//	Mapscene = Modescene;
//}

void QMyMap::Plantrequest_Ready(objectNames itemname, QPointF itemPos)
{
	ReadytoPlant->setVisible(true);
	QPoint tempPoint = PostoPoint(itemPos);
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
		if (isPlantedMap[x][y] == true)
		{
			ReadytoPlant_Shadow->setVisible(false);
			QStatusString.setPlainText(QString::number(x, 10) + " " + QString::number(y, 10) + ":True");
		}
		else
		{
			ReadytoPlant_Shadow->setPos(PointtoPos(tempPoint));
			ReadytoPlant_Shadow->setVisible(true);
			QStatusString.setPlainText(QString::number(x, 10) + " " + QString::number(y, 10) + ":False");
		}
	}
}

void QMyMap::Plantrequest_Try()
{
	if (ReadytoPlant_Shadow->isVisible())
	{
		pointNewItemtoPlantOn = PostoPoint(ReadytoPlant_Shadow->scenePos());
		emit addItem(ReadytoPlant->objectTypeNames, ReadytoPlant_Shadow->scenePos());
		QStatusString.setPlainText(QString::number(pointNewItemtoPlantOn.x(), 10) + " " + QString::number(pointNewItemtoPlantOn.y(), 10));
		Plantrequest_Done();
	}
	else
	{
		//判断如果点在画面的其他位置就取消
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
	default:
		break;
	}
}

void QMyMap::examineMap()
{
	for (const auto &i : PlantsinMap)
	{
		if (i->getHP() > 0)
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
		else if (i->getHP() < 0)
		{
			PlantsinMap.removeAll(i);
			i->Died();
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
				i->hurt(j);
				break;
			}
		}
		i->setPointinMap(PostoPoint(i->pos()));
		if (i->pos().x() > 1000)
		{
			removefromMap(Weapons, i);
		}
	}
/*	debugweek++;
	if (debugweek > 50)
	{
		int j = 0;
		for (const auto &i : PlantsinMap)
		{
			j++;
			qDebug() <<"Plants" << j << " " << i->getPointinMap().x() << " " << i->getPointinMap().y();
		}
		j = 0;
		for (const auto &i : ZombiesinMap)
		{
			j++;
			qDebug() << "Zombies" << j << " " << i->getPointinMap().x() << " " << i->getPointinMap().y();
		}
		j = 0;
		for (const auto &i : WeaponsinMap)
		{
			j++;
			qDebug() << "Weapons" << j << " " << i->getPointinMap().x() << " " << i->getPointinMap().y();
		}
		debugweek = 0;
	}*/
}

void QMyMap::Itemadded(QMyObject* newItemAdded)
{
	if (newItemAdded->getType() == Plants)
	{
		QPlants* newPlanttoLoad = (QPlants*)newItemAdded;
		int x = pointNewItemtoPlantOn.x();
		int y = pointNewItemtoPlantOn.y();
		isPlantedMap[x][y] = true;
		Map[x][y] = newPlanttoLoad;
		newPlanttoLoad->setPointinMap(x, y);
		PlantsinMap.push_back(newPlanttoLoad);
		//newPlanttoLoad->setMaptoLoad(this);
		connect(newPlanttoLoad, SIGNAL(addtomap(objectType, QMyObject*)), this, SLOT(addtoMap(objectType, QMyObject*)));
		connect(newPlanttoLoad, SIGNAL(removefrommap(objectType, QMyObject*)), this, SLOT(removefromMap(objectType, QMyObject*)));
	}
	else if (newItemAdded->getType() == Zombies)
	{
		newItemAdded->setPointinMap(PostoPoint(newItemAdded->pos()));
		ZombiesinMap.push_back((QZombies*)newItemAdded);
		connect(newItemAdded, SIGNAL(addtomap(objectType, QMyObject*)), this, SLOT(addtoMap(objectType, QMyObject*)));
		connect(newItemAdded, SIGNAL(removefrommap(objectType, QMyObject*)), this, SLOT(removefromMap(objectType, QMyObject*)));
	}
	
	QStatusString.setPlainText(QStatusString.toPlainText() + "\n" +QString::number(pointNewItemtoPlantOn.x(), 10) + " " + QString::number(pointNewItemtoPlantOn.y(), 10));

//	if (isPlantedMap[x][y])
//		QStatusString.setPlainText(QString::number(x, 10) + " " + QString::number(y, 10) + ":True");
//	else
//		QStatusString.setPlainText(QString::number(x, 10) + " " + QString::number(y, 10) + ":False");
}

void QMyMap::timerEvent(QTimerEvent *event)
{
	examineMap();
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
		myobject->Died();
	}
	break;
	case Zombies:
	{
		ZombiesinMap.removeAll((QZombies*)myobject);
		myobject->killMyTimer();
		delete myobject;
	}
	break;
	case Weapons:
	{
		WeaponsinMap.removeAll((QWeapons*)myobject);
		myobject->killMyTimer();
		delete myobject;
	}
	break;
	default:
		break;
	}
}