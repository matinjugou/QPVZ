#pragma once
#include "QMyObject.h"
#include "MyVariable.h"


class QMySunShine;
class QPlantsBomb;
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
	//�����Ƿ���в
	bool isThreatened();
	//���ù�����Χ�ж�����
	virtual bool inRange(QMyObject*) { return false; }
	//�����Ƿ���в
	void setThreatend(bool);
	//��������
	void Died();
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
	int Power;
public:
	QFightPlants(QGraphicsScene *parent = 0);
	~QFightPlants();
public:
	//��������
	void setPower(int);
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
	//��ʱ��ʱ��
	void timerEvent(QTimerEvent *event);
	//���
	void Shoot();
	//�ڹ�����Χ
	bool inRange(QMyObject*);
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
	//����һ������
	void makeSunShine();
	//��ʱ���¼�
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
	//��ʱ���¼�
	void timerEvent(QTimerEvent *event);
};

class QCherryBomb :public QFightPlants
{
protected:
	int						currentTime;		//��ʱ��ʱ��		
	bool					boomed;				//�Ƿ��Ѿ���ը
	QVector<QMyObject*>		enemytoKill;		//��¼Ҫɱ���ĵ���
public:
	QCherryBomb(QGraphicsScene *parent = 0);
	QCherryBomb(int x, int y, QGraphicsScene *parent = 0);
	~QCherryBomb();
public:
	//��ʱ���¼�
	void timerEvent(QTimerEvent *event);
	//�ڹ�����Χ
	bool inRange(QMyObject*);
};