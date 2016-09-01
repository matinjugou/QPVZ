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
	setPos(event->scenePos());//֮��Ҫ��ͼ����ӿ�����
	emit cursorMoved(event->scenePos());
}
