#pragma once
#include "QMyObject.h"
#include "MyVariable.h"


class QMySunShine;
class QPlantsBomb;
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
	//返回是否被威胁
	bool isThreatened();
	//设置攻击范围判定函数
	virtual bool inRange(QMyObject*) { return false; }
	//设置是否被威胁
	void setThreatend(bool);
	//死亡动画
	void Died();
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
	int Power;
public:
	QFightPlants(QGraphicsScene *parent = 0);
	~QFightPlants();
public:
	//设置力量
	void setPower(int);
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
	//计时器时间
	void timerEvent(QTimerEvent *event);
	//射击
	void Shoot();
	//在攻击范围
	bool inRange(QMyObject*);
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
	//制作一个阳光
	void makeSunShine();
	//计时器事件
	void timerEvent(QTimerEvent *event);
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
	//计时器事件
	void timerEvent(QTimerEvent *event);
};

class QCherryBomb :public QFightPlants
{
protected:
	int						currentTime;		//计时器时间		
	bool					boomed;				//是否已经爆炸
	QVector<QMyObject*>		enemytoKill;		//记录要杀死的敌人
public:
	QCherryBomb(QGraphicsScene *parent = 0);
	QCherryBomb(int x, int y, QGraphicsScene *parent = 0);
	~QCherryBomb();
public:
	//计时器事件
	void timerEvent(QTimerEvent *event);
	//在攻击范围
	bool inRange(QMyObject*);
};