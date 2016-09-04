#pragma once
#include "QMyObject.h"
#include "QWeapons.h"
#include "QFightMethods.h"
#include "MyVariable.h"
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
	objectNames		Plants_Name;	//ֲ�������
	bool			beThreatened;	//ֲ���Ƿ���в
public:
	QPlants(QGraphicsScene* parent = 0);
	~QPlants();
public:
	int getSunPrice();
	//��������ֵ
	bool isThreatened();
	//�����Ƿ���в
	virtual bool inRange(QMyObject*) { return false; }
	//���ù�����Χ�ж�����
	void setThreatend(bool);
	//�����Ƿ���в
	void setSunPrice(int);
	//��������ֵ
};

/* QPlants:			�����ֲ����
*@param CD:			ֲ��Ĺ����������λΪ����
*@param QWeapons:	ֲ�������
*/
class QBulletPlants :public QPlants
{
protected:
	int CD;			//�����ȴʱ�� 50 * ��ȴʱ��(s)
	int lastShoot;	//���һ��������

public:
	QBulletPlants(QGraphicsScene *parent = 0);
	~QBulletPlants();

public:
	int getCD();
	//�������CD
	virtual void Shoot(){}
	//���
	void setCD(int);
	//�������CD
};

class QFightPlants :public QPlants
{
protected:
	QFightMethods	*FightMethod;	//��������
public:
	QFightPlants(QGraphicsScene *parent = 0);
	~QFightPlants();
};

class QPeaShooter :public QBulletPlants
{
public:
	QPeas	*weapons;	//����
public:
	QPeaShooter(QGraphicsScene *parent = 0);
	QPeaShooter(int x, int y, QGraphicsScene *parent = 0);
	~QPeaShooter();
public:
	void timerEvent(QTimerEvent *event);
	//��ʱ��ʱ��
	void Shoot();
	//���
	void Died();
	//��������
	bool inRange(QMyObject*);
	//�ڹ�����Χ
};