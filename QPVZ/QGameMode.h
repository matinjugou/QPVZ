#pragma once
#include "QMyObject.h"
#include "QZombies.h"
#include "QPlants.h"
#include "qgraphicsscene.h"
#include "QMyButton.h"
#include "QCardBanks.h"
#include "QCardSelector.h"
#include "QMyMap.h"
struct Node
{
	objectNames Zombie_Type;
	int timetoshow;
};
enum GameModeNames{Surface, Adventure, NetFight};
class QGameMode :public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT
protected:
	QGraphicsScene *Scene;
	QGraphicsView *View;
signals:
	void exit();
	void exchangetoScene(QGraphicsScene*);
	void addItem(objectNames, QPointF); //要建立链接
	void Itemadded(QMyObject*);
public:
	QGameMode(QWidget *parent = 0);
	~QGameMode();
public:
	QGraphicsScene* getScene();
	void setView(QGraphicsView*);
};

class QGameMainMode :public QGameMode
{
	Q_OBJECT
public:
	QGameMainMode(QWidget* parent = 0);
	~QGameMainMode();
signals:
	void AdventureMode_Start(); //用signalmap改写
//	void NetFightMode_Start();
	void NewGameStart(GameModeNames);
	void Help_Start();
	void Setting_Options();
	void Quit_Game();
public:
	void timerEvent(QTimerEvent* event);
private:
	QMyObject *Background;
	QMyButton *StartGame_Adventure;
	QMyButton *StartGame_NetFight;
	QMyButton *Options;
	QMyButton *Help;
	QMyButton *Quit;
	QMyObject *Name_Card;
	QMyButton *Name_Change;
};

class QGameAdventureMode :public QGameMode
{
	Q_OBJECT
private:
	int currentTime;
	int stage;
	int horizontalScollBarValue;
	int TimerID;
	QCardSelector *Selector;	//应该在(0, 87)的位置
	QCardBank *Bank;
	QMyObject *Background;
	objectNames CardList[2] = {PeaShooter, PeaShooter};
	QMyMap *MappingSystem;
	int totZombies = 5;
	Node ZombiesList[5] = { {CommonZombie, 7} ,{ CommonZombie, 14 } ,
	{ CommonZombie, 21 } ,{ CommonZombie, 32 } ,{ CommonZombie, 40 }};	//可以修改为继承
public:
	QGameAdventureMode(QWidget *parent = 0);
	~QGameAdventureMode();
public:
	void timerEvent(QTimerEvent *event);
public slots:
	void GameStart();
};