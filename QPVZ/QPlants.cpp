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
	//TODO ËÀÍö¶¯»­
	qDebug() << "TimerKilled\n";
	setVisible(false);
	deleteLater();
	QPeaShooter *pPea = this;
	qDebug() << &pPea << "Dead\n";
}

void QPeaShooter::Shoot()
{
	weapons = new QPeas(pos().x() + 50, pos().y());
	qDebug() << "Hello, wordld";
	emit addtomap(Weapons, weapons);
//	connect(weapons, SIGNAL(addtomap(objectType, QMyObject*)), MaptoLoad, SLOT(addtoMap(objectType, QMyObject*)));
//	connect(weapons, SIGNAL(removefrommap(objectType, QMyObject*)), MaptoLoad, SLOT(removefromMap(objectType, QMyObject*)));
}

bool QPeaShooter::inRange(QMyObject* myobject)
{
	if ((myobject->getPointinMap().y() == PointinMap.y()) && (myobject->getPointinMap().x() <= 8))
	{
		qDebug() << "Plants" << " " << getPointinMap().x() << " " << getPointinMap().y();
		qDebug() << "Zombie" << " " << myobject->getPointinMap().x() << " " << myobject->getPointinMap().y() << "\n";
		return true;
	}
	return false;
}

QSunFlower::QSunFlower(QGraphicsScene *parent)
	:QPlants(parent)
{
	Plants_Name = SunFlower;
	HP = 300;
	lastSunShine = 0;

	myGif.setFileName("Resources/pvz-material/images/Plants/SunFlower/SunFlower1.gif");
	myGif.jumpToFrame(0);
	connect(&myGif, SIGNAL(frameChanged(int)), this, SLOT(setnewPixmap()));
	myGif.start();

	TimerID = startTimer(20);
}

QSunFlower::QSunFlower(int x, int y, QGraphicsScene *parent)
	:QPlants(parent)
{
	Plants_Name = SunFlower;
	HP = 300;
	lastSunShine = 0;
	setPos(x, y);

	myGif.setFileName("Resources/pvz-material/images/Plants/SunFlower/SunFlower1.gif");
	myGif.jumpToFrame(0);
	connect(&myGif, SIGNAL(frameChanged(int)), this, SLOT(setnewPixmap()));
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
	tempPos.setX();
	tempPos.setY();
	newSunShine->setPos(tempPos);
	Scene->addItem(newSunShine);
	tempPos.setY(MappingSystem->getRect().height() / 5 * (rand() % 4) + MappingSystem->getRect().y());
	newSunShine->moveTo(tempPos, 3000, QEasingCurve::Linear);
	connect(newSunShine, SIGNAL(BeTaken()), Bank, SLOT(SunShineAdded()));
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
