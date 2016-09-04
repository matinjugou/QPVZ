#pragma once
#include "QMyObject.h"
#include "MyVariable.h"

class QWeapons :public QMyObject
{
	Q_OBJECT
protected:
	int Power;
	int Speed;
	int Direction;
	bool beExcited;
	bool isWeaponUsed;
	QMyObject* enemy;
public:
	QWeapons(QGraphicsScene* parent = 0);
	~QWeapons();
public:
	virtual void hurt(){}
	void setPower(int);
	int getPower();
	void setSpeed(int);
	int getSpeed();
	void setDirection(int);
	int getDirection();
	int DeadTimeCount;
	int isDead;
	void setIsUsed(bool value)
	{
		isWeaponUsed = value;
	}
	void setIsExcited(bool value, QMyObject* myobject)
	{
		beExcited = value;
		enemy = myobject;
	}
	virtual bool inRange(QMyObject*) { return false; }
};

class QPeas :public QWeapons
{
public:
	QPeas(int x, int y, QGraphicsScene* parent = 0);
	QPeas(int power, int speed, int direction, int x, int y, QGraphicsScene* parent = 0);
	~QPeas();
public:
	void hurt();
	void timerEvent(QTimerEvent* event);
	bool inRange(QMyObject*);
};