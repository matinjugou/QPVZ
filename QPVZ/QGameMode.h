#pragma once
#include "QMyObject.h"
#include "QZombies.h"
#include "QPlants.h"
#include "qgraphicsscene.h"
#include "QMyButton.h"
#include "QCardBanks.h"
#include "QMyMap.h"
#include "QMySunShine.h"
#include "MyVariable.h"


class QMySunShine;
class QGameModeLoader;
class QMyObject;
class QCardSelector;

class QGameMode :public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT
protected:
	QGraphicsScene		*Scene;		//����
	QGraphicsView		*View;		//��ͼ����������������ɾ��
	QMyObject			*Background;

public:
	QGameMode(QGameModeLoader *parent = 0);
	~QGameMode();

signals:
	void exit();
	//�˳���ǰģʽ
	void exchangetoScene(QGraphicsScene*);
	//�л�����ģʽ�ĳ���
	void addItem(objectNames, QPointF);
	//�����Ʒ
	void Itemadded(QMyObject*);
	//����Ʒ�Ѿ���ӵ���Ϣ���´���

public:
	QGraphicsScene* getScene();
	//�õ���ǰģʽ�ĳ���
	void setView(QGraphicsView*);
	//���õ�ǰģʽ���ӽǣ����������ϵͳ������Ż���
};

class QGameMainMode :public QGameMode
{
	Q_OBJECT
private:
	QMyButton	*StartGame_Adventure;	//ð��ģʽ��ť
	QMyButton	*StartGame_NetFight;	//ð��ģʽ��ť
	QMyButton	*Options;				//ѡ�ť
	QMyButton	*Help;					//������ť
	QMyButton	*Quit;					//�˳���ť
	QMyObject	*Name_Card;				//������
	QMyButton	*Name_Change;			//������

public:
	QGameMainMode(QGameModeLoader* parent = 0);
	~QGameMainMode();

signals:
	void AdventureMode_Start(); 
	//ð��ģʽ��ʼ,��signalmap��д
	void NetFightMode_Start();
	//�����սģʽ��ʼ
	void NewGameStart(int);
	//����ĳ����Ϸģʽ
	void Help_Start();
	//������ʼ
	void Setting_Options();
	//��������

public:
	void timerEvent(QTimerEvent* event);
	//��ʱ���¼�

};

class QGameAdventureMode :public QGameMode
{
	Q_OBJECT
private:
	int					currentTime;				//��ʱ��ʱ��
	int					currentGame;				//��ǰ�ؿ�
	int					stage;						//��Ϸ�׶�
	int					TimerID;					//��ʱ��ID
	int					barMoveed;					//�������Ƿ��Ѿ��ƶ�
	QMySunShine			*newSunShine;				//�����������ָ��
	QPropertyAnimation	*animation;					//����
	QCardSelector		*Selector;					//��Ƭѡ����
	QCardBank			*Bank;						//��Ƭ��
	QMyMap				*MappingSystem;				//��ͼ����
	objectNames			CardList[2] = {PeaShooter, PeaShooter};		//��ѡ��Ƭ�����֮࣬���дΪ�ļ���ȡ
	int					totZombies = 5;				//�ܹ��Ľ�ʬ���������Ը�Ϊ�ļ���ȡ
	Node				ZombiesList[5] = { {CommonZombie, 7} ,{ CommonZombie, 14 } ,
						{ CommonZombie, 21 } ,{ CommonZombie, 32 } ,{ CommonZombie, 40 }};	//��ʬ���ֺͳ��ֵ�ʱ�䣬�����޸�����ļ�
public:
	QGameAdventureMode(QGameModeLoader *parent = 0);
	~QGameAdventureMode();

public slots:
	void GameStart();
	//��Ϸ��ʼ

public:
	void timerEvent(QTimerEvent *event);
	//��ʱ��ʱ��
	void moveScrollBar(int fromvalue, int arrivevalue, int duration);
	//�ƶ�View�Ĺ�����
};