#include "QPlants.h"

QPlants::QPlants(QWidget* parent)
//	:QMyObject(parent)
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

QBulletPlants::QBulletPlants(QWidget* parent)
//	:QPlants(parent)
{
	lastShoot = 0;
}

QBulletPlants::~QBulletPlants()
{

}

QPeaShooter::QPeaShooter(QWidget* parent)
//	: QBulletPlants(parent)
{
	Plants_Name = PeaShooter;
	objectTypeName = Plants;
	HP = 300;
	CD = 70;
	lastShoot = CD;
	TimerID = startTimer(20);
	myGif.setFileName("Resources/pvz-material/images/Plants/Peashooter/Peashooter.gif");
	myGif.jumpToFrame(0);
	connect(&myGif, SIGNAL(frameChanged(int)), this, SLOT(setnewPixmap()));
	myGif.start();
}

QPeaShooter::QPeaShooter(int x, int y, QWidget *parent)
//	: QBulletPlants(parent)
{
	Plants_Name = PeaShooter;
	objectTypeName = Plants;
	HP = 300;
	CD = 70;
	lastShoot = CD;
	setPos(x, y);
	TimerID = startTimer(20);
	myGif.setFileName("Resources/pvz-material/images/Plants/Peashooter/Peashooter.gif");
	myGif.jumpToFrame(0);
	connect(&myGif, SIGNAL(frameChanged(int)), this, SLOT(setnewPixmap()));
	myGif.start();
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
	weapons = new QPeas(pos().x() + 10, pos().y());
//	weapons->setParentItem(this);
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