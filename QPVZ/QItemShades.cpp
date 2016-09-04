#include "QItemShades.h"
#include "QMyMap.h"
QItemShade::QItemShade(QMyMap *parent)
	:QObject(parent)
{

}

QItemShade::~QItemShade()
{

}

//public
QPoint QItemShade::getPointinMap()
{
	return PointinMap;
}

void QItemShade::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	QRectF PixBoundingRect = boundingRect();
	setPos(event->scenePos().x() - (PixBoundingRect.width() / 2), event->scenePos().y() - (PixBoundingRect.height() / 2));//之后要让图标更加靠近中
//	setPos(0, 0);
	emit cursorMoved(event->scenePos());
}

void QItemShade::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		emit leftButtonClicked();
	}
	else
	{
		emit rightButtonClicked();
	}
}

void QItemShade::LoadPixmap(const QString &filename)
{
	setPixmap(QPixmap(filename));
}

void QItemShade::setPointinMap(QPoint temppoint)
{
	PointinMap = temppoint;
}