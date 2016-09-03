#include "QZombies.h"
#include <stdlib.h>
#include <iostream>

QZombies::QZombies(QWidget* parent)
//	:QMyObject(parent)
{
	objectTypeName = Zombies;
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


QCommonZombie::QCommonZombie(QWidget *parent)
{

}

QCommonZombie::QCommonZombie(int x, int y, QWidget *parent)
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

//	myGif.setFileName("Resources/pvz-material/images/Zombies/Zombie/Zombie3.gif");

	WalkType = (int)(rand() % 3) + 4;
	setMyGif(WalkType);
	Zombie_Name = CommonZombie;
	objectTypeName = Zombies;
	HP = 200;
	Speed = 1;
	Direction = -1;
	Power = 2;
	beExcited = false;
	Enemy = NULL;
	hurtStarted = false;
	hurtStoped = true;
	setPos(x, y);
	Walkstop = 0;

//	myGif.jumpToFrame(0);
//	connect(&myGif, SIGNAL(frameChanged(int)), this, SLOT(setnewPixmap()));
//	myGif.start();
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
		Walkstop++;	//等待调参数
		if ((Walkstop < 16))
			setPos(pos().x() + Direction * Speed, pos().y());
	//	else if (Walkstop > 36)
		else if (Walkstop > 40)
			Walkstop = 0;
	}
}

