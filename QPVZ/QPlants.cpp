#include "QPlants.h"
#include "QMySunShine.h"
#include "QWeapons.h"
#include "QFightMethods.h"

QPlants::QPlants(QGraphicsScene* parent)
	:QMyObject(parent)
{
	objectTypeName = Plants;
	beThreatened = false;
}

void QPlants::setThreatend(bool value)
{
	beThreatened = value;
}

bool QPlants::isThreatened()
{
	return beThreatened;
}

QPlants::~QPlants()
{

}

QBulletPlants::QBulletPlants(QGraphicsScene * parent)
	:QPlants(parent)
{
}

QBulletPlants::~QBulletPlants()
{
}

QPeaShooter::QPeaShooter(QGraphicsScene *parent)
	: QBulletPlants(parent)
{
	Plants_Name = PeaShooter;
	HP = 300;
	CD = 70;
	lastShoot = CD;
	
	myGif.setFileName("Resources/pvz-material/images/Plants/Peashooter/Peashooter.gif");
	myGif.jumpToFrame(0);
	connect(&myGif, SIGNAL(frameChanged(int)), this, SLOT(setnewPixmap()));
	myGif.start();

	TimerID = startTimer(20);
}

QPeaShooter::QPeaShooter(int x, int y, QGraphicsScene *parent)
	: QBulletPlants(parent)
{
	Plants_Name = PeaShooter;
	HP = 300;
	CD = 70;
	lastShoot = CD;
	setPos(x, y);
	
	myGif.setFileName("Resources/pvz-material/images/Plants/Peashooter/Peashooter.gif");
	myGif.jumpToFrame(0);
	connect(&myGif, SIGNAL(frameChanged(int)), this, SLOT(setnewPixmap()));
	myGif.start();

	TimerID = startTimer(20);
}

QPeaShooter::~QPeaShooter()
{

}

void QPeaShooter::timerEvent(QTimerEvent *event)
{
	if (HP <= 0)
	{
		killTimer(TimerID);
		emit removefrommap(Plants, this);
		Died();
		return;
	}
	if (beThreatened)
	{
		if (lastShoot == CD)
		{
			lastShoot = 0;
			Shoot();
		}
		lastShoot++;
	}
	else
	{
		lastShoot = CD;
	}
}

void QPeaShooter::Died()
{
	setVisible(false);
	deleteLater();
}

void QPeaShooter::Shoot()
{
	weapons = new QPeas(pos().x() + 50, pos().y());
	emit addtomap(Weapons, weapons);
}

bool QPeaShooter::inRange(QMyObject* myobject)
{
	if ((myobject->getPointinMap().y() == PointinMap.y()) && (myobject->getPointinMap().x() <= 8))
	{
		return true;
	}
	return false;
}

QSunFlower::QSunFlower(QGraphicsScene *parent)
	:QPlants(parent)
{
	Plants_Name = SunFlower;
	HP = 300;
	lastSunShine = 800;

	myGif.setFileName("Resources/pvz-material/images/Plants/SunFlower/SunFlower1.gif");
	myGif.jumpToFrame(0);
	connect(&myGif, SIGNAL(frameChanged(int)), this, SLOT(setnewPixmap()));
	myGif.setSpeed(140);
	myGif.start();

	TimerID = startTimer(20);
}

QSunFlower::QSunFlower(int x, int y, QGraphicsScene *parent)
	:QPlants(parent)
{
	Plants_Name = SunFlower;
	HP = 300;
	lastSunShine = 800;
	setPos(x, y);

	myGif.setFileName("Resources/pvz-material/images/Plants/SunFlower/SunFlower1.gif");
	myGif.jumpToFrame(0);
	connect(&myGif, SIGNAL(frameChanged(int)), this, SLOT(setnewPixmap()));
	myGif.setSpeed(140);
	myGif.start();

	TimerID = startTimer(20);
}

QSunFlower::~QSunFlower()
{

}

void QSunFlower::makeSunShine()
{
	newSunShine = new QMySunShine(this->scene());
	QPointF tempPos;
	tempPos.setX(pos().x() + (boundingRect().width() - newSunShine->boundingRect().width()) / 2);
	tempPos.setY(pos().y() - newSunShine->boundingRect().height() + 5);
	newSunShine->setPos(tempPos);
	newSunShine->setZValue(PointinMap.y() + 10);
	scene()->addItem(newSunShine);
	
	QPropertyAnimation *SunShineAnimation = new QPropertyAnimation(newSunShine, "pos");
	SunShineAnimation->setDuration(800);
	SunShineAnimation->setStartValue(tempPos);
	
	tempPos.setX(tempPos.x() + 7);
	tempPos.setY(tempPos.y() - 15);
	SunShineAnimation->setKeyValueAt(0.3, tempPos);

	tempPos.setX(tempPos.x() + 8);
	tempPos.setY(tempPos.y() + 75);
	SunShineAnimation->setEndValue(tempPos);

	SunShineAnimation->setEasingCurve(QEasingCurve::OutInCubic);
	SunShineAnimation->start();

	emit addtomap(SunShine, newSunShine);
}

void QSunFlower::timerEvent(QTimerEvent *event)
{
	if (HP <= 0)
	{
		killTimer(TimerID);
		emit removefrommap(Plants, this);
		Died();
		return;
	}
	lastSunShine++;
	if (lastSunShine == 1200)
	{
		makeSunShine();
		lastSunShine = 0;
	}
}

void QSunFlower::Died()
{
	//TODO ËÀÍö¶¯»­
	setVisible(false);
	deleteLater();
}

QWallNut::QWallNut(QGraphicsScene *parent)
	:QPlants(parent)
{
	Plants_Name = WallNut;
	HP = 4000;
	status = 0;

	QMovie *newQMovie;
	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Plants/WallNut/WallNut.gif");
	Gifs.push_back(newQMovie);

	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Plants/WallNut/Wallnut_cracked1.gif");
	Gifs.push_back(newQMovie);

	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Plants/WallNut/Wallnut_cracked2.gif");
	Gifs.push_back(newQMovie);

	setMyGif(0);

	TimerID = startTimer(20);
}

QWallNut::QWallNut(int x, int y, QGraphicsScene *parent)
	:QPlants(parent)
{
	Plants_Name = WallNut;
	HP = 4000;
	status = 0;
	setPos(x, y);

	QMovie *newQMovie;
	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Plants/WallNut/WallNut.gif");
	Gifs.push_back(newQMovie);

	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Plants/WallNut/Wallnut_cracked1.gif");
	Gifs.push_back(newQMovie);

	newQMovie = new QMovie;
	newQMovie->setFileName("Resources/pvz-material/images/Plants/WallNut/Wallnut_cracked2.gif");
	Gifs.push_back(newQMovie);

	setMyGif(0);

	TimerID = startTimer(20);
}

QWallNut::~QWallNut()
{

}

void QWallNut::timerEvent(QTimerEvent *event)
{
	if (HP <= 0)
	{
		killTimer(TimerID);
		emit removefrommap(Plants, this);
		Died();
		return;
	}
	else if ((HP > 0) && (HP <= 1333))
	{
		if (status == 1)
		{
			status = 2;
			setMyGif(2);
		}
	}
	else if ((HP > 1333) && (HP <= 2666))
	{
		if (status == 0)
		{
			status = 1;
			setMyGif(1);
		}
	}
}

void QWallNut::Died()
{
	//TODO ËÀÍö¶¯»­
	setVisible(false);
	deleteLater();
}