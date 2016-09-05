#pragma once
#include "QMyObject.h"
#include "MyVariable.h"


class QMySunShine;
class QFightMethods;
class QPeas;

/* QPlants:			植物类
*@param HP:			植物的生命值
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
	bool isThreatened();
	//返回是否被威胁
	virtual bool inRange(QMyObject*) { return false; }
	//设置攻击范围判定函数
	void setThreatend(bool);
	//设置是否被威胁
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

class QSunFlower :public QPlants
{
	Q_OBJECT
protected:
	int				lastSunShine;	//上一次创建阳光的间隔
	QMySunShine		*newSunShine;	//新的阳光指针
public:
	QSunFlower(QGraphicsScene *parent = 0);
	QSunFlower(int x, int y, QGraphicsScene *parent = 0);
	~QSunFlower();

public:
	void makeSunShine();
	//制作一个阳光
	void timerEvent(QTimerEvent *event);
	//计时器事件
	void Died();
	//死亡处理
};

class QWallNut :public QPlants
{
	Q_OBJECT
protected:
	int status;

public:
	QWallNut(QGraphicsScene *parent = 0);
	QWallNut(int x, int y, QGraphicsScene *parent = 0);
	~QWallNut();

public:
	void timerEvent(QTimerEvent *event);
	//计时器事件
	void Died();
	//死亡处理
};