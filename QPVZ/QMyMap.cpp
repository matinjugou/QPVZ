#include "QMyMap.h"

QMyMap::QMyMap(QWidget *parent)
{
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
		{
			Map[i][j] = NULL;
			isPlantedMap[i][j] = false;
		}
	MapRect.setX(0);
	MapRect.setY(0);
	MapRect.setWidth(0);
	MapRect.setHeight(0);

	for (int i = 0; i < 5; i++)
	{
		verticalLines[i] = MapRect.x() + MapRect.width() / 5 * i;
		horizontalLines[i] = MapRect.y() + MapRect.height() / 5 * i;
	}
	ReadytoPlant = new QItemShade;
	ReadytoPlant_Shadow = new QItemShade;
	connect(ReadytoPlant, SIGNAL(leftButtonClicked()), this, SLOT(Plantrequest_Try()));
	connect(ReadytoPlant, SIGNAL(rightButtonClicked()), this, SLOT(Plantrequest_Done()));
	connect(ReadytoPlant, SIGNAL(rightButtonClicked()), this, SIGNAL(RequesCancelled()));
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
	for (int i = 0; i < 4; i++)
	{
		if ((itemPos.x() >= verticalLines[i]) && (itemPos.x() < verticalLines[i + 1]))
		{
			tempPoint.setX(i);
		}
		if ((itemPos.y() >= horizontalLines[i]) && (itemPos.y() < horizontalLines[i + 1]))
		{
			tempPoint.setY(i);
		}
	}
	return tempPoint;
}

QPointF QMyMap::PointtoPos(QPoint itemPoint)
{
	QPointF tempPointF;
	tempPointF.setX(verticalLines[itemPoint.x()]);
	tempPointF.setX(horizontalLines[itemPoint.y()]);
	return tempPointF;
}

void QMyMap::Plantrequest_Ready(objectNames itemname, QPointF itemPos)
{
	QPoint tempPoint = PostoPoint(itemPos);
	int x = tempPoint.x();
	int y = tempPoint.y();
	changePixmap(itemname);
	ReadytoPlant->setPos(itemPos); //之后要让图片更可能处于中心
	ReadytoPlant->grabMouse();
	ReadytoPlant->setVisible(true);
	if (isPlantedMap[x][y] == true)
	{
		ReadytoPlant_Shadow->setVisible(false);
	}
	else
	{
		setPos(PointtoPos(tempPoint));
		ReadytoPlant_Shadow->setVisible(true);
	}
}

void QMyMap::Plantrequest_Update(QPointF itemPos)
{
	QPoint tempPoint = PostoPoint(itemPos);
	int x = tempPoint.x();
	int y = tempPoint.y();
	if (isPlantedMap[x][y] == true)
	{
		ReadytoPlant_Shadow->setVisible(false);
	}
	else
	{
		setPos(PointtoPos(tempPoint));
		ReadytoPlant_Shadow->setVisible(true);
	}
}

void QMyMap::Plantrequest_Try()
{
	if (ReadytoPlant_Shadow->isVisible())
	{
		addItem(ReadytoPlant->objectTypeNames, ReadytoPlant_Shadow->scenePos());
		pointNewItemtoPlantOn = PostoPoint(ReadytoPlant_Shadow->scenePos());
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
	
}

void QMyMap::examineMap()
{
	for (const auto &i : PlantsinMap)
	{
		for (const auto &j : ZombiesinMap)
		{
			if (i->inRange(j))
			{
				i->threadtened();
				break;
			}
		}
	}
}

void QMyMap::Itemadded(QMyObject* newItemAdded)
{
	int x = pointNewItemtoPlantOn.x();
	int y = pointNewItemtoPlantOn.y();
	isPlantedMap[x][y] = true;
	Map[x][y] = newItemAdded;
}

void QMyMap::timerEvent(QTimerEvent *event)
{

}