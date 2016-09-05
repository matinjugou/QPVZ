#include "QMyShovel.h"
#include "QGameMode.h"

QMyShovel::QMyShovel(QGameAdventureMode *parent)
	:QMyObject(parent)
{
	setPixmap(QPixmap("Resources/pvz-material/images/Buttons/Shovel.png"));
	status = false;
}

QMyShovel::QMyShovel(int x, int y, QGameAdventureMode *parent)
	: QMyObject(parent)
{
	setPixmap(QPixmap("Resources/pvz-material/images/Buttons/Shovel.png"));
	status = false;
	setPos(x, y);
	OriginPos = QPointF(x, y);
}

QMyShovel::~QMyShovel()
{
}

void QMyShovel::setOriginPos(QPointF originpos)
{
	OriginPos = originpos;
}

void QMyShovel::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		if (!status)
		{
			QPointF tempPos = event->scenePos();
			status = true;
			setPos(tempPos.x(), tempPos.y() - boundingRect().height());
			grabMouse();
		}
		else
		{
			status = false;
			emit leftButtonClicked(event->scenePos());
			setPos(OriginPos);
			ungrabMouse();
		}
	}
	else if (event->button() == Qt::RightButton)
	{
		if (status)
		{
			setPos(OriginPos);
			status = false;
			ungrabMouse();
		}
	}
}

void QMyShovel::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	QPointF tempPos = event->scenePos();
	setPos(tempPos.x(), tempPos.y() - boundingRect().height());
}