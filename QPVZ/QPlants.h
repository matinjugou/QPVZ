#pragma once
#include "QMyObject.h"
#include "MyVariable.h"


class QMySunShine;
class QFightMethods;
class QPeas;

/* QPlants:			ֲ����
*@param HP:			ֲ�������ֵ
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
	bool isThreatened();
	//�����Ƿ���в
	virtual bool inRange(QMyObject*) { return false; }
	//���ù�����Χ�ж�����
	void setThreatend(bool);
	//�����Ƿ���в
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

class QSunFlower :public QPlants
{
	Q_OBJECT
protected:
	int				lastSunShine;	//��һ�δ�������ļ��
	QMySunShine		*newSunShine;	//�µ�����ָ��
public:
	QSunFlower(QGraphicsScene *parent = 0);
	QSunFlower(int x, int y, QGraphicsScene *parent = 0);
	~QSunFlower();

public:
	void makeSunShine();
	//����һ������
	void timerEvent(QTimerEvent *event);
	//��ʱ���¼�
	void Died();
	//��������
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
	//��ʱ���¼�
	void Died();
	//��������
};