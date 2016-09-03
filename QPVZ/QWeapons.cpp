#include "QWeapons.h"
#include "QZombies.h"
#include "QPlants.h"

QWeapons::QWeapons(QWidget* parent)
//	:QMyObject(parent)
{

}

QWeapons::~QWeapons()
{

}

QPeas::QPeas(int power, int speed, int direction, int x, int y, QWidget* parent)
//	: QWeapons(parent)
{
	Pictures.push_back(QPixmap("Resources/pvz-material/images/weapoons/Pea.png"));
	Pictures.push_back(QPixmap("Resources/pvz-material/images/weapoons/PeaBulletHit.png"));
	setMyPixmap(0);
	Power = power;
	Speed = speed;
	setPos(x, y);
	Direction = direction;
	TimerID = startTimer(20);
	emit addtomap(Weapons, this);
}
QPeas::QPeas(int x, int y, QWidget* parent)
//	: QWeapons(parent)
{
	Pictures.push_back(QPixmap("Resources/pvz-material/images/weapoons/Pea.png"));
	Pictures.push_back(QPixmap("Resources/pvz-material/images/weapoons/PeaBulletHit.png"));
	setMyPixmap(0);
	Power = 20;
	Speed = 10;
	setPos(x, y);
	Direction = 1;
	TimerID = startTimer(20);
	emit addtomap(Weapons, this);
}

QPeas::~QPeas()
{

}

void QPeas::hurt(QMyObject* enemy)
{
	if (enemy->getType() == Zombies)
	{
		QZombies *zombie = (QZombies* )enemy;
		zombie->killHP(Power);
	}
	Died();
}

void QPeas::timerEvent(QTimerEvent* event)
{
	setPos(pos().x() + Speed * Direction, pos().y());
}

bool QPeas::inRange(QMyObject* myobject)
{
	if (myobject->getPointinMap() == PointinMap)
		return true;
	return false;
}