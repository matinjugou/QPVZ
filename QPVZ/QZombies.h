#pragma once
#include "QMyObject.h"
#include "QEquipments.h"

class QZombies:public QMyObject
{
	Q_OBJECT
	Q_PROPERTY(QPointF pos READ pos WRITE setPos)
protected:
	int Power;
	int Speed;
	int Direction;
	int WalkType;
	int Walkstop;
	int movestatus;
	bool hurtStoped;
	bool hurtStarted;
	int DeadTimeCount;
	objectNames Zombie_Name;
	QEquipments *Equipment;
	bool beExcited;//%
	QMyObject* Enemy;
public:
	QZombies(QWidget *parent = 0);
	~QZombies();
public:
	virtual void hurt();
	virtual bool inRange(QMyObject*) { return false; }
	void setExcited(bool);
	void setEnemy(QMyObject*);
	bool isExcited();
};

class QCommonZombie :public QZombies
{
public:
	QCommonZombie(QWidget *parent = 0);
	QCommonZombie(int x, int y, QWidget *parent = 0);
	~QCommonZombie();
public:
	void hurt();
	bool inRange(QMyObject*);
	void timerEvent(QTimerEvent *event);
	void walk();
};

