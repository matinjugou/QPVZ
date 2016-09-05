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
#include "qfile.h"
#include "qdatastream.h"


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
	int						currentTime;				//��ʱ��ʱ��
	int						currentGame;				//��ǰ�ؿ�
	int						stage;						//��Ϸ�׶�
	int						TimerID;					//��ʱ��ID
	int						barMoveed;					//�������Ƿ��Ѿ��ƶ�
	qint32					Level;						//��ǰ�ؿ�
	QFile					SettingsFile;				//�����ļ�
	QMySunShine				*newSunShine;				//�����������ָ��
	QPropertyAnimation		*animation;					//����
	QCardSelector			*Selector;					//��Ƭѡ����
	QCardBank				*Bank;						//��Ƭ��
	QMyMap					*MappingSystem;				//��ͼ����
	int						totCards;					//��ѡ��Ƭ��������
	QVector<objectNames>	CardList;					//��ѡ��Ƭ�����֮࣬���дΪ�ļ���ȡ
	qint32					totZombies;					//�ܹ��Ľ�ʬ���������Ը�Ϊ�ļ���ȡ
	QVector<Node>			ZombiesList;				//��ʬ���ֺͳ��ֵ�ʱ�䣬�����޸�����ļ�
public:
	QGameAdventureMode(QGameModeLoader *parent = 0);
	~QGameAdventureMode();

public slots:
	//��Ϸ��ʼ
	void GameStart();

public:
	//��ʱ��ʱ��
	void timerEvent(QTimerEvent *event);
	//�ƶ�View�Ĺ�����
	void moveScrollBar(int fromvalue, int arrivevalue, int duration);
	//����ȡ�Ľ�ʬ����ת��Ϊ��Ӧ��ö������
	objectNames zombieTypeInttoEnum(int);
	//����ȡ��ֲ������ת��Ϊ��Ӧ��ö������
	objectNames plantTypeInttoEnum(int);
};