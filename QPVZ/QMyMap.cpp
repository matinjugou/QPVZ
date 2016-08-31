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
}

QMyMap::~QMyMap()
{

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
	if (isPlantedMap[x][y] == true)
	{
		ReadytoPlant->setVisible(false);
	}
	else
	{
		changePixmap(itemname);
		setPos(PointtoPos(tempPoint));
		ReadytoPlant->setVisible(true);
	}
}

