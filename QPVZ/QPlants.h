#pragma once
#include "QMyObject.h"
#include "QWeapons.h"
#include "QFightMethods.h"
//#include "QMyMap.h"

/* QPlants:			ֲ����
*@param HP:			ֲ�������ֵ
*@param Sunprice:	ֲ�������ֵ
*@param CD:			ֲ���ˢ��ʱ��
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

/* QPlants:			�����ֲ����
*@param CD:			ֲ��Ĺ����������λΪ����
*@param QWeapons:	ֲ�������
*/
class QBulletPlants :public QPlants
{
protected:
	int CD; //50 * ��ȴʱ��(s)
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