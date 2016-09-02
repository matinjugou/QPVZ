#include "QMyObject.h"
#include "math.h"
QMyObject::QMyObject(QWidget *parent)
//	:QObject(parent)
{
//	connect(timer, SIGNAL(finished(QPrivateSignal)), this, SIGNAL(moveStop()));
}

QMyObject::~QMyObject()
{

}

objectType QMyObject::getType()
{
	return objectTypeName;
}

void QMyObject::moveTo(int x, int y, int speed)	//ÐèÒªÖØÐ´
{
	int totFrame = abs((pos().y() - y)) / ((double)speed);
	int stepx = (x - pos().x()) / ((double)speed);
	int stepy = (y - pos().y()) / ((double)speed);
	timer = new QTimeLine(totFrame * 20);
	timer->setFrameRange(0, totFrame);

	animation = new QGraphicsItemAnimation;
	animation->setItem(this);
	animation->setTimeLine(timer);

	for (int i = 0; i < totFrame; ++i)
		animation->setPosAt(i / ((double)totFrame), QPointF(pos().x() + stepx, pos().y() + stepy));

	timer->start();
}

void QMyObject::pushbackPixmap(QPixmap pic)
{
	Pictures.push_back(pic);
}

void QMyObject::setMyPixmap(int i)
{
	setPixmap(Pictures[i]);
}

QPixmap QMyObject::getPicture(int i)
{
	return Pictures[i];
}