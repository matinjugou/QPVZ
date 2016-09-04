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
	QGraphicsScene		*Scene;		//场景
	QGraphicsView		*View;		//视图，引入对象树后可以删除
	QMyObject			*Background;

public:
	QGameMode(QGameModeLoader *parent = 0);
	~QGameMode();

signals:
	void exit();
	//退出当前模式
	void exchangetoScene(QGraphicsScene*);
	//切换到该模式的场景
	void addItem(objectNames, QPointF);
	//添加物品
	void Itemadded(QMyObject*);
	//将物品已经添加的消息向下传递

public:
	QGraphicsScene* getScene();
	//得到当前模式的场景
	void setView(QGraphicsView*);
	//设置当前模式的视角，引入对象树系统后可以优化掉
};

class QGameMainMode :public QGameMode
{
	Q_OBJECT
private:
	QMyButton	*StartGame_Adventure;	//冒险模式按钮
	QMyButton	*StartGame_NetFight;	//冒险模式按钮
	QMyButton	*Options;				//选项按钮
	QMyButton	*Help;					//帮助按钮
	QMyButton	*Quit;					//退出按钮
	QMyObject	*Name_Card;				//姓名牌
	QMyButton	*Name_Change;			//改姓名

public:
	QGameMainMode(QGameModeLoader* parent = 0);
	~QGameMainMode();

signals:
	void AdventureMode_Start(); 
	//冒险模式开始,用signalmap改写
	void NetFightMode_Start();
	//网络对战模式开始
	void NewGameStart(int);
	//开启某种游戏模式
	void Help_Start();
	//帮助开始
	void Setting_Options();
	//设置启动

public:
	void timerEvent(QTimerEvent* event);
	//计时器事件

};

class QGameAdventureMode :public QGameMode
{
	Q_OBJECT
private:
	int					currentTime;				//计时器时间
	int					currentGame;				//当前关卡
	int					stage;						//游戏阶段
	int					TimerID;					//计时器ID
	int					barMoveed;					//滚动条是否已经移动
	QMySunShine			*newSunShine;				//创建新阳光的指针
	QPropertyAnimation	*animation;					//动画
	QCardSelector		*Selector;					//卡片选择器
	QCardBank			*Bank;						//卡片商
	QMyMap				*MappingSystem;				//地图处理
	objectNames			CardList[2] = {PeaShooter, PeaShooter};		//可选卡片的种类，之后改写为文件读取
	int					totZombies = 5;				//总共的僵尸数量，可以改为文件读取
	Node				ZombiesList[5] = { {CommonZombie, 7} ,{ CommonZombie, 14 } ,
						{ CommonZombie, 21 } ,{ CommonZombie, 32 } ,{ CommonZombie, 40 }};	//僵尸名字和出现的时间，可以修改外接文件
public:
	QGameAdventureMode(QGameModeLoader *parent = 0);
	~QGameAdventureMode();

public slots:
	void GameStart();
	//游戏开始

public:
	void timerEvent(QTimerEvent *event);
	//计时器时间
	void moveScrollBar(int fromvalue, int arrivevalue, int duration);
	//移动View的滚动条
};