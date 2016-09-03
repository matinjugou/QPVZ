#pragma once
#include "QMyObject.h"

class QWeapons :public QMyObject
{
	Q_OBJECT
protected:
	int Power;
	int Speed;
	int Direction;
public:
	QWeapons(QWidget* parent = 0);
	~QWeapons();
public:
	virtual void hurt(QMyObject *enemy){}
	void setPower(int);
	int getPower();
	void setSpeed(int);
	int getSpeed();
	void setDirection(int);
	int getDirection();

	virtual bool inRange(QMyObject*) { return false; }
};

class QPeas :public QWeapons
{
public:
	QPeas(int x, int y, QWidget* parent = 0);
	QPeas(int power, int speed, int direction, int x, int y, QWidget* parent = 0);
	~QPeas();
public:
	void hurt(QMyObject *enemy);
	void timerEvent(QTimerEvent* event);
	bool inRange(QMyObject*);
};