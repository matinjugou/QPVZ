#pragma once
#include "QMyObject.h"

class QWeapoons :public QMyObject
{
protected:
	int Power;
	int Speed;
	int Direction;
public:
	QWeapoons(QWidget* parent = 0);
	~QWeapoons();
public:
	virtual void hurt(QMyObject *enemy);
	void setPower(int);
	int getPower();
	void setSpeed(int);
	int getSpeed();
	void setDirection(int);
	int getDirection();
};

class QPeas :public QWeapoons
{
public:
	QPeas(int x, int y, QWidget* parent = 0);
	QPeas(int power = 20, int speed = 10, int direction = 1, int x = 0, int y = 0, QWidget* parent = 0);
	~QPeas();
public:
	void hurt(QMyObject *enemy);
	void timerEvent(QTimerEvent* event);
};