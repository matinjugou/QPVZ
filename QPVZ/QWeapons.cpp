#include "QWeapons.h"
#include "QZombies.h"
#include "QPlants.h"

QWeapons::QWeapons(QGraphicsScene* parent)
	:QMyObject(parent)
{
	isWeaponUsed = false;
	beExcited = false;
	isDead = 0;
	DeadTimeCount = 0;
}

QWeapons::~QWeapons()
{

}

QPeas::QPeas(int power, int speed, int direction, int x, int y, QGraphicsScene* parent)
	: QWeapons(parent)
{
	Pictures.push_back(QPixmap("Resources/pvz-material/images/weapoons/Pea.png"));
	Pictures.push_back(QPixmap("Resources/pvz-material/images/weapoons/PeaBulletHit.png"));
	setMyPixmap(0);
	Power = power;
	Speed = speed;
	setPos(x, y);
	Direction = direction;
	TimerID = startTimer(20);
}

QPeas::QPeas(int x, int y, QGraphicsScene* parent)
	: QWeapons(parent)
{
	Pictures.push_back(QPixmap("Resources/pvz-material/images/weapoons/Pea.png"));
	Pictures.push_back(QPixmap("Resources/pvz-material/images/weapoons/PeaBulletHit.png"));
	setMyPixmap(0);
	Power = 20;
	Speed = 5;
	setPos(x, y);
	Direction = 1;
	TimerID = startTimer(20);
}

QPeas::~QPeas()
{

}

void QPeas::hurt()
{
	if (!isWeaponUsed)
	{
		if (enemy->getType() == Zombies)
		{
			QZombies *zombie = (QZombies*)enemy;
			zombie->killHP(Power);
			isWeaponUsed = true;
		}
	}
//	Died();
}

void QPeas::timerEvent(QTimerEvent* event)
{
	if (beExcited)
	{
		hurt();
	}
	if (isWeaponUsed)
	{
		emit removefrommap(Weapons, this);
		if (isDead == 0)
		{
			setPixmap(Pictures[1]);
			isDead++;
		}
		DeadTimeCount++;
		if ((DeadTimeCount > 7) && (isDead == 1))
		{
			setVisible(false);
			isDead++;
		}
		if ((DeadTimeCount > 50) && (isDead == 2))
		{
			killTimer(TimerID);
			delete this;
		}
		return;
	}
	setPos(pos().x() + Speed * Direction, pos().y());
}

bool QPeas::inRange(QMyObject* myobject)
{
	QPointF tempPos = myobject->pos();
	tempPos.setX(tempPos.x() + myobject->boundingRect().width() / 2);
	if ((((tempPos.x() - 5) < pos().x()) && ((tempPos.x() + 5) > pos().x())) && (myobject->getPointinMap().y() == PointinMap.y()))
		return true;
	return false;
}