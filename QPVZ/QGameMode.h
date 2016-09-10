#pragma once
#include "QMyObject.h"
#include "qgraphicsscene.h"
#include "QMyButton.h"
#include "MyVariable.h"
#include "qfile.h"
#include "qdatastream.h"
#include "qtcpserver.h"
#include "qtcpsocket.h"
#include "QMyDialog.h"
#include "qmediaplayer.h"

class QMySunShine;
class QGameModeLoader;
class QMyObject;
class QCardSelector;
class QMyShovel;
class QMyMap;
class QCardBanks;
class QMySunShine;
class QMyProcessor;

class QGameMode :public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT
protected:
	QGraphicsScene		*Scene;					//����
	QGraphicsView		*View;					//��ͼ
	QMyObject			*Background;			//����
	QMediaPlayer		*backgroundMusic;		//BGM

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
	//���²���BGM
	void replayBGM(QMediaPlayer::State);
};

class QGameMainMode :public QGameMode
{
	Q_OBJECT
private:
	int				currentTime;			//��ǰʱ��
	int				TimerID;				//��ʱ��ID
	int				ModetoStart;			//��Ҫ��������Ϸģʽ
	int				ModeButtonStatus;		//��Ҫ��������Ϸģʽ�İ�ť����ʽ
	QMyButton		*StartGame_Adventure;	//ð��ģʽ��ť
	QMyButton		*StartGame_NetFight;	//ð��ģʽ��ť
	QMyButton		*Options;				//ѡ�ť
	QMyButton		*Help;					//������ť
	QMyButton		*Quit;					//�˳���ť
	QMyObject		*Name_Card;				//������
	QMyButton		*Name_Change;			//������
	QMyObject		*zombieHand;			//������ʬ����
	QSignalMapper	*Mapper;				//�źŵ�ͼ
	QMediaPlayer	*eveilLaugh;			//��ʬ�����������Ч
	QMediaPlayer	*gameStartSound;		//��ʬ�����������Ч

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
	int						GameOverTiemerCount;		//��Ϸʧ���˳�����ʱ
	int						GameOverTiemerID;			//��Ϸʧ�ܼ�ʱ��
	bool					isGameOvered;				//��Ϸ�Ƿ������
	bool					Gamewin1;					//ʤ������һ���Ƿ����н�ʬ������
	bool					Gamewin2;					//ʤ�����������Ƿ��н�ʬû���ϳ�
	QMyObject				*GameOverPix;				//��Ϸʧ�ܻ���
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
	qint32					totZombies;					//�ܹ��Ľ�ʬ���������Ը�Ϊ�ļ���ȡ
	QVector<Node>			ZombiesList;				//��ʬ���ֺͳ��ֵ�ʱ�䣬�����޸�����ļ�
	int						totCards;					//��ѡ��Ƭ��������
	QVector<objectNames>	CardList;					//��ѡ��Ƭ�����֮࣬���дΪ�ļ���ȡ
	int						readyToPlantCount;			//׼������ֲ��ͼƬ����
	QMediaPlayer			*readyToPlantBGM;			//׼������ֲ�����Ч
	QMyObject				*readyToPlantText;			//׼������ֲ����ʾ

public:
	QGameAdventureMode(QGameModeLoader *parent = 0);
	~QGameAdventureMode();

public slots:
	//��Ϸ��ʼ
	void GameStart();
	//��Ϸ����
	void GameOver();
	//��Ϸʤ������һ�ı�
	void GameConditionChanged(bool);

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

class QGameNetFightMode :public QGameMode
{
	Q_OBJECT
private:
	bool					asServer;					//�Ƿ���Ϊ������
	QString					ipStr;						//IP��ַ
	int						currentTime;				//��ʱ��ʱ��
	int						TimerID;					//��ʱ��ID
	int						stage;						//��Ϸ״̬
	int						barMoveed;					//�������Ƿ��Ѿ��ƶ�
	int						timeCouner;					//ֲ��ʤ����ʱ��
	QMyObject				*ZombieLine;				//��ʬ����ֲ�߽���
	qint32					Level;						//��ǰ�ؿ�
	QFile					SettingsFile;				//�����ļ�
	QMySunShine				*newSunShine;				//�����������ָ��
	QPropertyAnimation		*animation;					//����
	QCardSelector			*Selector;					//��Ƭѡ����
	QCardBank				*Bank;						//��Ƭ��
	QMyMap					*MappingSystem;				//��ͼ����
	QMyButton				*QuitGame;					//�˳����o
	QTcpServer				*Server;					//������
	QTcpSocket				*Socket;					//�׽���
	QMyDialog				*myDialog;					//�Ի���
	int						totCards;					//��ѡ��Ƭ��������
	QVector<objectNames>	CardList;					//��ѡ��Ƭ�����֮࣬���дΪ�ļ���ȡ
	int						readyToPlantCount;			//׼������ֲ��ͼƬ����
	QMediaPlayer			*readyToPlantBGM;			//׼������ֲ�����Ч
	QMyObject				*readyToPlantText;			//׼������ֲ����ʾ

public:
	QGameNetFightMode(QGameModeLoader* parent = 0);
	~QGameNetFightMode();

public slots:
	//��Ϸ��ʼ
	void GameStart();
	//�յ���������Ʒ����Ϣ
	void getMessage();
	//������������Ʒ����Ϣ
	void sendMessage(objectNames, QPointF);

public:
	//��ʼ������
	bool InitTcpConnection();
	//���ؿ�Ƭ��Դ
	void LoadMyCard();
	//������ֲ�¼�����
	void InitAddItemConnection();
	//��ʱ���¼�
	void timerEvent(QTimerEvent *event);
	//�ƶ�View�Ĺ�����
	void moveScrollBar(int fromvalue, int arrivevalue, int duration);
	//����ȡ�Ľ�ʬ����ת��Ϊ��Ӧ��ö������
	objectNames zombieTypeInttoEnum(int);
	//����ȡ��ֲ������ת��Ϊ��Ӧ��ö������
	objectNames plantTypeInttoEnum(int);
	//����Ʒ���������ַ���ת��Ϊ��Ӧ��ö������
	objectNames itemStringtoObjectnames(QString);
	//����Ʒ��������ö������ת��Ϊ��Ӧ���ַ���
	QString itemObjectnamestoString(objectNames);
};