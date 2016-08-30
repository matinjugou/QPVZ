#pragma once
#include "QMyObject.h"
#include "QEquipments.h"

class QZombies:public QMyObject
{
protected:
	int HP;
	int Power;
	QEquipments *Equipment;
public:
	QZombies(QWidget *parent = 0);
	~QZombies();
public:
	virtual void hurt(QMyObject *enemy);
	void setHP(int hp)
	{
		HP = hp;
	}
	void killHP(int hp)
	{
		HP -= hp;
	}
};

