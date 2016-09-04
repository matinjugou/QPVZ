#pragma once
#include "QMyObject.h"
#include "QWeapons.h"
#include "QFightMethods.h"
#include "MyVariable.h"
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
	objectNames		Plants_Name;	//植物的名字
	bool			beThreatened;	//植物是否被威胁
public:
	QPlants(QGraphicsScene* parent = 0);
	~QPlants();
public:
	int getSunPrice();
	//返回阳光值
	bool isThreatened();
	//返回是否被威胁
	virtual bool inRange(QMyObject*) { return false; }
	//设置攻击范围判定函数
	void setThreatend(bool);
	//设置是否被威胁
	void setSunPrice(int);
	//设置阳光值
};

/* QPlants:			射击型植物类
*@param CD:			植物的攻击间隔，单位为毫秒
*@param QWeapons:	植物的武器
*/
class QBulletPlants :public QPlants
{
protected:
	int CD;			//射击冷却时间 50 * 冷却时间(s)
	int lastShoot;	//最后一次射击间隔

public:
	QBulletPlants(QGraphicsScene *parent = 0);
	~QBulletPlants();

public:
	int getCD();
	//返回射击CD
	virtual void Shoot(){}
	//射击
	void setCD(int);
	//设置射击CD
};

class QFightPlants :public QPlants
{
protected:
	QFightMethods	*FightMethod;	//攻击方法
public:
	QFightPlants(QGraphicsScene *parent = 0);
	~QFightPlants();
};

class QPeaShooter :public QBulletPlants
{
public:
	QPeas	*weapons;	//武器
public:
	QPeaShooter(QGraphicsScene *parent = 0);
	QPeaShooter(int x, int y, QGraphicsScene *parent = 0);
	~QPeaShooter();
public:
	void timerEvent(QTimerEvent *event);
	//计时器时间
	void Shoot();
	//射击
	void Died();
	//死亡动画
	bool inRange(QMyObject*);
	//在攻击范围
};