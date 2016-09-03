#pragma once
#include "QMyObject.h"
#include "QWeapons.h"
#include "QFightMethods.h"
//#include "QMyMap.h"

/* QPlants:			植物类
*@param HP:			植物的生命值
*@param Sunprice:	植物的阳关值
*@param CD:			植物的刷新时间
*/
class QPlants :public QMyObject
{
	Q_OBJECT
protected:
//	QMyMap* MaptoLoad;
	objectNames Plants_Name;
	bool beThreatened;
public:
	QPlants(QWidget* parent = 0);
	~QPlants();
public:
//	void setMaptoLoad(QMyMap* mymaptoload)
//	{
//		MaptoLoad = mymaptoload;
//	}
	void setThreatend(bool);
	void setSunPrice(int);
	int getSunPrice();
	virtual bool inRange(QMyObject*) { return false; }
	bool isThreatened();
};

/* QPlants:			射击型植物类
*@param CD:			植物的攻击间隔，单位为毫秒
*@param QWeapons:	植物的武器
*/
class QBulletPlants :public QPlants
{
protected:
	int CD; //50 * 冷却时间(s)
	int lastShoot;
public:
	QBulletPlants(QWidget *parent = 0);
	~QBulletPlants();
public:
	virtual void Shoot(){}
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
	QPeas *weapons;
public:
	QPeaShooter(QWidget *parent = 0);
	QPeaShooter(int x, int y, QWidget *parent = 0);
	~QPeaShooter();
public:
	void timerEvent(QTimerEvent *event);
	void Shoot();
	void Died();
	bool inRange(QMyObject*);
};