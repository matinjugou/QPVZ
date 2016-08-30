#pragma once
#include "QMyObject.h"
#include "QWeapoons.h"
#include "QFightMethods.h"


/* QPlants:			ֲ����
*@param HP:			ֲ�������ֵ
*@param Sunprice:	ֲ�������ֵ
*@param CD:			ֲ���ˢ��ʱ��
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

/* QPlants:			�����ֲ����
*@param CD:			ֲ��Ĺ����������λΪ����
*@param QWeapoons:	ֲ�������
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