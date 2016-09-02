#include "QPlants.h"

QPlants::QPlants(QWidget* parent)
//	:QMyObject(parent)
{
	objectTypeName = Plants;
	beThreatened = false;
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
	HP = 300;
	CD = 1400;
	setPos(parent->pos().x(), parent->pos().y());
	
	startTimer (20);
}

QPeaShooter::QPeaShooter(int x, int y, QWidget *parent)
//	: QBulletPlants(parent)
{
	HP = 300;
	CD = 1400;
	setPos(x, y);
	
	startTimer (20);
}


QPeaShooter::~QPeaShooter()
{

}

void QPeaShooter::timerEvent(QTimerEvent *event)
{
	if (HP <= 0)
	{
		Died();
	}
	if (beThreatened)
	{

	}
}

void QPeaShooter::Died()
{
	//TODO ËÀÍö¶¯»­
	setVisible(false);
}

void QPeaShooter::Shoot()
{

}