#pragma once
#include "QMyObject.h"
#include "QWeapoons.h"
#include "QFightMethods.h"


/* QPlants:			植物类
*@param HP:			植物的生命值
*@param Sunprice:	植物的阳关值
*@param CD:			植物的刷新时间
*/
class QPlants :public QMyObject
{
	Q_OBJECT
protected:
	int HP;
	int SunPrice;
	bool beThreatened;
public:
	QPlants(QWidget* parent = 0);
	~QPlants();
public:
	void setHP(int);
	void killHP(int);
	int getHP();
	void setSunPrice(int);
	int getSunPrice();
};

/* QPlants:			射击型植物类
*@param CD:			植物的攻击间隔，单位为毫秒
*@param QWeapoons:	植物的武器
*/
class QBulletPlants :public QPlants
{
protected:
	int CD;
	int lastShoot;
	QWeapoons *Weapoon;
public:
	QBulletPlants(QWidget *parent = 0);
	~QBulletPlants();
public:
	virtual void shoot();
	void setCD(int);
	int getCD();
};

class QFightPlants :public QPlants
{
protected:
	QFightMethods *FightMethod;
public:
	QFightPlants(QWidget *parent = 0);
	~QFightPlants();
};

class QPeaShooter :public QBulletPlants
{
public:
	QPeaShooter(QWidget *parent = 0);
	QPeaShooter(int x, int y, QWidget *parent = 0);
	~QPeaShooter();
public:
	void timerEvent(QTimerEvent *event);
	void shoot();
	void Died();
};