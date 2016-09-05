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

QBucketHeadZombie::QBucketHeadZombie(QGraphicsScene *parent)
	:QZombies(parent)
{
	QMovie *newQMovie;
	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Zombies/BucketheadZombie/1.gif");
	Gifs.push_back(newQMovie);
	
	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Zombies/BucketheadZombie/BucketheadZombie.gif");
	Gifs.push_back(newQMovie);
	
	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Zombies/BucketheadZombie/BucketheadZombieAttack.gif");
	Gifs.push_back(newQMovie);

	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Zombies/Zombie/BoomDie.gif");
	Gifs.push_back(newQMovie);

	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Zombies/Zombie/Zombie2.gif");
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

	WalkType = 1;
	setMyGif(WalkType);
	Zombie_Name = BucketHeadZombie;
	HP = 1300;
	Speed = 1;
	Direction = -1;
	Power = 2;
	status = 1;

	TimerID = startTimer(20);
}

QBucketHeadZombie::QBucketHeadZombie(int x, int y, QGraphicsScene *parent)
	:QZombies(parent)
{
	QMovie *newQMovie;
	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Zombies/BucketheadZombie/1.gif");
	Gifs.push_back(newQMovie);

	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Zombies/BucketheadZombie/BucketheadZombie.gif");
	Gifs.push_back(newQMovie);

	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Zombies/BucketheadZombie/BucketheadZombieAttack.gif");
	Gifs.push_back(newQMovie);

	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Zombies/Zombie/BoomDie.gif");
	Gifs.push_back(newQMovie);

	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Zombies/Zombie/Zombie2.gif");
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

	WalkType = 1;
	setMyGif(WalkType);
	Zombie_Name = BucketHeadZombie;
	HP = 1300;
	Speed = 1;
	Direction = -1;
	Power = 2;
	status = 1;
	setPos(x, y);

	TimerID = startTimer(20);
}

QBucketHeadZombie::~QBucketHeadZombie()
{

}

bool QBucketHeadZombie::inRange(QMyObject* myobject)
{
	if (myobject->getPointinMap() == PointinMap)
		return true;
	return false;
}

void QBucketHeadZombie::hurt()
{
	Enemy->killHP(Power);
}

void QBucketHeadZombie::timerEvent(QTimerEvent *event)
{
	if (HP < 0)
	{
		if (isDead == 0)
		{
			emit removefrommap(Zombies, this);
			setMyGif(8);
			isDead++;
		}
		DeadTimeCount++;
		if (DeadTimeCount <= 70)
		{
			walk();
		}
		if ((DeadTimeCount > 70) && (isDead == 1))
		{
			setMyGif(6);
			isDead++;
		}
		if (DeadTimeCount > 100)
		{
			killTimer(TimerID);
			delete this;
		}
		return;
	}
	else if ((HP > 0) && (HP < 200))
	{
		if (status == 1)
		{
			status = 2;
			if (beExcited)
				setMyGif(5);
			else
				setMyGif(4);
		}
	}
	if (beExcited)
	{
		if (!hurtStarted)
		{
			hurtStarted = true;
			hurtStoped = false;
			if (status == 1)
			{
				setMyGif(2);
			}
			else
			{
				setMyGif(5);
			}
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
			if (status == 1)
			{
				setMyGif(1);
			}
			else
			{
				setMyGif(4);
			}
		}
		walk();
	}
}

void QBucketHeadZombie::walk()
{
	Walkstop++;
	if (Walkstop < 75)
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

QPoleVaultingZombie::QPoleVaultingZombie(QGraphicsScene *parent)
	:QZombies(parent)
{
	QMovie *newQMovie;
	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Zombies/PoleVaultingZombie/1.gif");
	Gifs.push_back(newQMovie);

	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Zombies/PoleVaultingZombie/PoleVaultingZombie.gif");
	Gifs.push_back(newQMovie);

	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Zombies/PoleVaultingZombie/PoleVaultingZombieAttack.gif");
	Gifs.push_back(newQMovie);

	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Zombies/Zombie/BoomDie.gif");
	Gifs.push_back(newQMovie);

	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Zombies/PoleVaultingZombie/PoleVaultingZombieJump.gif");
	Gifs.push_back(newQMovie);
	connect(newQMovie, SIGNAL(finished()), this, SLOT(ChangeGif()));

	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Zombies/PoleVaultingZombie/PoleVaultingZombieJump2.gif");
	Gifs.push_back(newQMovie);
	connect(newQMovie, SIGNAL(finished()), this, SLOT(ChangeGif2()));

	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Zombies/PoleVaultingZombie/PoleVaultingZombieLostHead.gif");
	Gifs.push_back(newQMovie);

	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Zombies/PoleVaultingZombie/PoleVaultingZombieLostHeadWalk.gif");
	Gifs.push_back(newQMovie);

	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Zombies/PoleVaultingZombie/ZombieLostHead.gif");
	Gifs.push_back(newQMovie);

	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Zombies/PoleVaultingZombie/PoleVaultingZombieWalk.gif");
	Gifs.push_back(newQMovie);

	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Zombies/PoleVaultingZombie/PoleVaultingZombieDie.gif");
	Gifs.push_back(newQMovie);

	WalkType = 1;
	setMyGif(WalkType);
	Zombie_Name = PoleVaultingZombie;
	HP = 500;
	Speed = 1;
	Direction = -1;
	Power = 2;
	status = 1;
	Jumping = 0;

	TimerID = startTimer(20);
}

QPoleVaultingZombie::QPoleVaultingZombie(int x, int y, QGraphicsScene *parent)
	:QZombies(parent)
{
	QMovie *newQMovie;
	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Zombies/PoleVaultingZombie/1.gif");
	Gifs.push_back(newQMovie);

	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Zombies/PoleVaultingZombie/PoleVaultingZombie.gif");
	Gifs.push_back(newQMovie);

	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Zombies/PoleVaultingZombie/PoleVaultingZombieAttack.gif");
	Gifs.push_back(newQMovie);

	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Zombies/Zombie/BoomDie.gif");
	Gifs.push_back(newQMovie);

	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Zombies/PoleVaultingZombie/PoleVaultingZombieJump.gif");
	Gifs.push_back(newQMovie);
	connect(newQMovie, SIGNAL(finished()), this, SLOT(ChangeGif()));

	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Zombies/PoleVaultingZombie/PoleVaultingZombieJump2.gif");
	Gifs.push_back(newQMovie);
	connect(newQMovie, SIGNAL(finished()), this, SLOT(ChangeGif2()));

	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Zombies/PoleVaultingZombie/PoleVaultingZombieLostHead.gif");
	Gifs.push_back(newQMovie);

	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Zombies/PoleVaultingZombie/PoleVaultingZombieLostHeadWalk.gif");
	Gifs.push_back(newQMovie);

	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Zombies/PoleVaultingZombie/ZombieLostHead.gif");
	Gifs.push_back(newQMovie);

	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Zombies/PoleVaultingZombie/PoleVaultingZombieWalk.gif");
	Gifs.push_back(newQMovie);

	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Zombies/PoleVaultingZombie/PoleVaultingZombieDie.gif");
	Gifs.push_back(newQMovie);

	WalkType = 1;
	setMyGif(WalkType);
	Zombie_Name = PoleVaultingZombie;
	HP = 500;
	Speed = 1;
	Direction = -1;
	Power = 2;
	status = 1;
	Jumping = 0;
	setPos(x, y);

	TimerID = startTimer(20);
}

QPoleVaultingZombie::~QPoleVaultingZombie()
{

}

bool QPoleVaultingZombie::inRange(QMyObject* myobject)
{
	if (status == 1)
	{
		if ((myobject->getPointinMap().y() == PointinMap.y()) && 
			((((myobject->pos().x() + myobject->boundingRect().width()) + 2) >= (pos().x() + 200)) &&
				(((myobject->pos().x() + myobject->boundingRect().width()) - 2) <= (pos().x() + 200))))
			return true;
		return false;
	}
	else if (status == 2)
	{
		if (myobject->getPointinMap() == PointinMap)
			return true;
		else return false;
	}
}

void QPoleVaultingZombie::ChangeGif()
{
	Gifs[4]->stop();
	setMyGif(5);
	setPos(pos().x() - 135, pos().y());
	Jumping++;
}

void QPoleVaultingZombie::ChangeGif2()
{
	Gifs[5]->stop();
	Jumping++;
}


void QPoleVaultingZombie::hurt()
{
	Enemy->killHP(Power);
}

void QPoleVaultingZombie::timerEvent(QTimerEvent *event)
{
	if (HP < 0)
	{
		if (isDead == 0)
		{
			emit removefrommap(Zombies, this);
			if (status == 1)
				setMyGif(6);
			else
				setMyGif(7);
			isDead++;
		}
		DeadTimeCount++;
		if (DeadTimeCount <= 70)
		{
			walk();
		}
		if ((DeadTimeCount > 70) && (isDead == 1))
		{
			setMyGif(10);
			isDead++;
		}
		if (DeadTimeCount > 100)
		{
			killTimer(TimerID);
			delete this;
		}
		return;
	}
	if ((beExcited) || ((Jumping != 4) && (Jumping != 0)))
	{
		if (status == 1)
		{
			if (Jumping == 0)
			{
				setMyGif(4);
//				moveTo(pos().x() - 50, pos().y(), 1000);
				Jumping++;
			}
			if (Jumping == 3)
			{
				setMyGif(9);//////////////
				status = 2;
				Jumping++;
			}
		}
		else
		{
			if (!hurtStarted)
			{
				hurtStarted = true;
				hurtStoped = false;
				setMyGif(2);
			}
			hurt();
		}
	}
	else 
	{
		if (!hurtStoped)
		{
			hurtStarted = false;
			hurtStoped = true;
			Walkstop = 0;
			if (status == 1)
			{
				setMyGif(1);
			}
			else
			{
				setMyGif(9);
			}
		}
		if ((Jumping == 0) || (Jumping == 4))
			walk();
	}
}

void QPoleVaultingZombie::walk()
{
	Walkstop++;
	if (status == 1)
	{
		if (Walkstop < 25)
		{
			if (movestatus == 0)
			{
				moveTo(pos().x() - 16, pos().y(), 500, QEasingCurve::Linear);
				movestatus = 1;
			}
		}
		else if (Walkstop > 25)
		{
			Walkstop = 0;
			movestatus = 0;
		}
	}
	else
	{
		if (Walkstop < 100)
		{
			if (movestatus == 0)
			{
				moveTo(pos().x() - 10, pos().y(), 2000);
				movestatus = 1;
			}
		}
		else if (Walkstop > 100)
		{
			Walkstop = 0;
			movestatus = 0;
		}
	}
}