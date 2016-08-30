#include "QWeapoons.h"
#include "QZombies.h"
#include "QPlants.h"

QWeapoons::QWeapoons(QWidget* parent)
	:QMyObject(parent)
{

}

QWeapoons::~QWeapoons()
{

}

QPeas::QPeas(int power, int speed, int direction, int x, int y, QWidget* parent)
	: QWeapoons(parent)
{
	Pictures[0].load("Resources/pvz-material/images/weapoons/Pea.png");
	Pictures[1].load("Resources/pvz-material/images/weapoons/PeaBulletHit.png");
	Power = power;
	Speed = speed;
	setPos(x, y);
	Direction = direction;

	startTimer(20);
}
QPeas::QPeas(int x, int y, QWidget* parent)
	: QWeapoons(parent)
{
	Pictures[0].load("Resources/pvz-material/images/weapoons/Pea.png");
	Pictures[1].load("Resources/pvz-material/images/weapoons/PeaBulletHit.png");
	Power = 20;
	Speed = 10;
	setPos(x, y);
	Direction = 1;

	startTimer(20);
}

QPeas::~QPeas()
{

}

void QPeas::hurt(QMyObject* enemy)
{
	if (enemy->getType() == objectType::Zombies)
	{
		QZombies *zombie = (QZombies* )enemy;
		zombie->killHP(Power);
	}
	Died();
}

void QPeas::timerEvent(QTimerEvent* event)
{
	Pos.x = Pos.x + Speed * Direction;

}