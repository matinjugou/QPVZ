#include "QPlants.h"

QPlants::QPlants(QWidget* parent = 0)
	:QMyObject(parent)
{
	Type = Plants;
	beThreatened = false;
}

QPlants::~QPlants()
{

}

QBulletPlants::QBulletPlants(QWidget* parent = 0)
	:QPlants(parent)
{
	lastShoot = 0;
}

QPeaShooter::QPeaShooter(QWidget* parent)
	: QBulletPlants(parent)
{
	HP = 300;
	CD = 1400;
	setPos(parent->pos.x, parent->pos.y);
	Gif[0].setGif("Resources/pvz-material/images/Plants/Peashooter.Peashooter.gif");
	
	startTimer (20);
}

QPeaShooter::QPeaShooter(int x, int y, QWidget *parent = 0)
	: QBulletPlants(parent)
{
	HP = 300;
	CD = 1400;
	setPos(x, y);
	Gif[0].setGif("Resources/pvz-material/images/Plants/Peashooter.Peashooter.gif");

	startTimer (20);
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