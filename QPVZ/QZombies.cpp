#include "QZombies.h"
#include <stdlib.h>
#include <iostream>

QZombies::QZombies(QGraphicsScene* parent)
	:QMyObject(parent)
{
	objectTypeName = Zombies;
	beExcited = false;
	Enemy = NULL;
	hurtStarted = false;
	hurtStoped = true;
	isDead = 0;
	Walkstop = 0;
	DeadTimeCount = 0;
	movestatus = 0;
}

QZombies::~QZombies()
{

}

void QZombies::hurt()
{

}

bool QZombies::isExcited()
{
	return beExcited;
}

void QZombies::setEnemy(QMyObject* enemy)
{
	Enemy = enemy;
}

void QZombies::setExcited(bool value)
{
	beExcited = value;
}

QCommonZombie::QCommonZombie(QGraphicsScene *parent)
	:QZombies(parent)
{
	QMovie *newQMovie;
	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Zombies/Zombie/1.gif");
	Gifs.push_back(newQMovie);

	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Zombies/Zombie/2.gif");
	Gifs.push_back(newQMovie);

	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Zombies/Zombie/3.gif");
	Gifs.push_back(newQMovie);

	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Zombies/Zombie/BoomDie.gif");
	Gifs.push_back(newQMovie);

	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Zombies/Zombie/Zombie.gif");
	Gifs.push_back(newQMovie);

	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Zombies/Zombie/Zombie2.gif");
	Gifs.push_back(newQMovie);

	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Zombies/Zombie/Zombie3.gif");
	Gifs.push_back(newQMovie);

	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Zombies/Zombie/ZombieAttack.gif");
	Gifs.push_back(newQMovie);

	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Zombies/Zombie/ZombieDie.gif");
	Gifs.push_back(newQMovie);

	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Zombies/Zombie/ZombieHead.gif");
	Gifs.push_back(newQMovie);

	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Zombies/Zombie/ZombieLostHead.gif");
	Gifs.push_back(newQMovie);

	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Zombies/Zombie/ZombieLostHeadAttack.gif");
	Gifs.push_back(newQMovie);

	WalkType = (int)(rand() % 3) + 4;
	setMyGif(WalkType);
	Zombie_Name = CommonZombie;
	HP = 200;
	Speed = 1;
	Direction = -1;
	Power = 2;

	TimerID = startTimer(20);
}

QCommonZombie::QCommonZombie(int x, int y, QGraphicsScene *parent)
	:QZombies(parent)
{
	QMovie *newQMovie;
	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Zombies/Zombie/1.gif");
	Gifs.push_back(newQMovie);

	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Zombies/Zombie/2.gif");
	Gifs.push_back(newQMovie);
	
	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Zombies/Zombie/3.gif");
	Gifs.push_back(newQMovie);

	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Zombies/Zombie/BoomDie.gif");
	Gifs.push_back(newQMovie);
	
	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Zombies/Zombie/Zombie.gif");
	Gifs.push_back(newQMovie);

	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Zombies/Zombie/Zombie2.gif");
	Gifs.push_back(newQMovie);

	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Zombies/Zombie/Zombie3.gif");
	Gifs.push_back(newQMovie);

	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Zombies/Zombie/ZombieAttack.gif");
	Gifs.push_back(newQMovie);

	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Zombies/Zombie/ZombieDie.gif");
	Gifs.push_back(newQMovie);

	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Zombies/Zombie/ZombieHead.gif");
	Gifs.push_back(newQMovie);

	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Zombies/Zombie/ZombieLostHead.gif");
	Gifs.push_back(newQMovie);

	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Zombies/Zombie/ZombieLostHeadAttack.gif");
	Gifs.push_back(newQMovie);

	WalkType = (int)(rand() % 3) + 4;
	setMyGif(WalkType);
	Zombie_Name = CommonZombie;
	HP = 200;
	Speed = 1;
	Direction = -1;
	Power = 2;
	setPos(x, y);

	TimerID = startTimer(20);
}

QCommonZombie::~QCommonZombie()
{

}

bool QCommonZombie::inRange(QMyObject* myobject)
{
	if (myobject->getPointinMap() == PointinMap)
		return true;
	return false;
}

void QCommonZombie::hurt()
{
	Enemy->killHP(Power);
}

void QCommonZombie::timerEvent(QTimerEvent *event)
{
	if (HP < 0)
	{
		if (isDead == 0)
		{
			emit removefrommap(Zombies, this);
			setMyGif(10);
			isDead++;
		}
		DeadTimeCount++;
		if (DeadTimeCount <= 70)
		{
			walk();
		}
		if ((DeadTimeCount > 70) && (isDead == 1))
		{
			setMyGif(8);
			isDead++;
		}
		if (DeadTimeCount > 100)
		{
			killTimer(TimerID);
			delete this;
		}
		return;
	}
	if (beExcited)
	{
		if (!hurtStarted)
		{
			hurtStarted = true;
			hurtStoped = false;
			setMyGif(7);
		}
		hurt();
	}
	else
	{
		if (!hurtStoped)
		{
			hurtStarted = false;
			hurtStoped = true;
			Walkstop = 0;
			setMyGif(WalkType);
		}
		walk();
	}
}

void QCommonZombie::walk()
{
	Walkstop++;
	switch (WalkType)
	{
	case 4:
	{
		if ((Walkstop < 55))
		{
			if (movestatus == 0)
			{
				moveTo(pos().x() - 16, pos().y(), 550);
				movestatus = 1;
			}
		}
		else if (Walkstop > 55)
		{
			Walkstop = 0;
			movestatus = 0;
		}
	}
	break;
	case 5:
	{
		if ((Walkstop < 75))
		{
			if (movestatus == 0)
			{
				moveTo(pos().x() - 16, pos().y(), 750);
				movestatus = 1;
			}
		}
		else if (Walkstop > 75)
		{
			Walkstop = 0;
			movestatus = 0;
		}
	}
	break;
	case 6:
	{
		if ((Walkstop < 45))
		{
			if (movestatus == 0)
			{
				moveTo(pos().x() - 16, pos().y(), 450);
				movestatus = 1;
			}
		}
		else if (Walkstop > 45)
		{
			Walkstop = 0;
			movestatus = 0;
		}
	}
	break;
	default:
		break;
	}
}

