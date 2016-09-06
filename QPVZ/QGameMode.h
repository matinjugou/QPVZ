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
#include "QMyShovel.h"
#include "QMyProcessor.h"

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
	//�˳���ǰģʽ
	void exit();
	//�л�����ģʽ�ĳ���
	void exchangetoScene(QGraphicsScene*);
	//�����Ʒ
	void addItem(objectNames, QPointF);
	//����Ʒ�Ѿ���ӵ���Ϣ���´���
	void Itemadded(QMyObject*);

public:
	//�õ���ǰģʽ�ĳ���
	QGraphicsScene* getScene();
	//���õ�ǰģʽ���ӽǣ����������ϵͳ������Ż���
	void setView(QGraphicsView*);
};

class QGameMainMode :public QGameMode
{
	Q_OBJECT
private:
	int				currentTime;			//��ǰʱ��
	int				TimerID;				//��ʱ��ID
	int				ModetoStart;			//��Ҫ��������Ϸģʽ
	int				ModeButtonStatus;				//��Ҫ��������Ϸģʽ�İ�ť����ʽ
	QMyButton		*StartGame_Adventure;	//ð��ģʽ��ť
	QMyButton		*StartGame_NetFight;	//ð��ģʽ��ť
	QMyButton		*Options;				//ѡ�ť
	QMyButton		*Help;					//������ť
	QMyButton		*Quit;					//�˳���ť
	QMyObject		*Name_Card;				//������
	QMyButton		*Name_Change;			//������
	QMyObject		*zombieHand;			//������ʬ����
	QSignalMapper	*Mapper;				//�źŵ�ͼ

public:
	QGameMainMode(QGameModeLoader* parent = 0);
	~QGameMainMode();

signals:
	//����ĳ����Ϸģʽ
	void NewGameStart(int);
	//������ʼ
	void Help_Start();
	//��������
	void Setting_Options();

public slots:
	//����ĳ����Ϸģʽ�붯��
	void beforeNewGameStart(int);

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
	bool					firstZombieShowed;			//��һֻ��ʬ�Ƿ��Ѿ�����
	qint32					Level;						//��ǰ�ؿ�
	QFile					SettingsFile;				//�����ļ�
	QMySunShine				*newSunShine;				//�����������ָ��
	QPropertyAnimation		*animation;					//����
	QCardSelector			*Selector;					//��Ƭѡ����
	QCardBank				*Bank;						//��Ƭ��
	QMyShovel				*Shovel;					//����
	QMyObject				*Shovel_Bank;				//���Ӳ�
	QMyProcessor			*MyProcessorBar;			//������
	QMyMap					*MappingSystem;				//��ͼ����
	QMyButton				*QuitGame;					//�˳����o
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