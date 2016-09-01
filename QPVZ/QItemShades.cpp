#include "QItemShades.h"

QItemShade::QItemShade(QWidget *parent)
{

}

QItemShade::~QItemShade()
{

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

void QItemShade::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	setPos(event->scenePos());//之后要让图标更加靠近中
	emit cursorMoved(event->scenePos());
}
