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
	QGraphicsScene		*Scene;		//场景
	QGraphicsView		*View;		//视图，引入对象树后可以删除
	QMyObject			*Background;

public:
	QGameMode(QGameModeLoader *parent = 0);
	~QGameMode();

signals:
	//退出当前模式
	void exit();
	//切换到该模式的场景
	void exchangetoScene(QGraphicsScene*);
	//添加物品
	void addItem(objectNames, QPointF);
	//将物品已经添加的消息向下传递
	void Itemadded(QMyObject*);

public:
	//得到当前模式的场景
	QGraphicsScene* getScene();
	//设置当前模式的视角，引入对象树系统后可以优化掉
	void setView(QGraphicsView*);
};

class QGameMainMode :public QGameMode
{
	Q_OBJECT
private:
	int				currentTime;			//当前时间
	int				TimerID;				//计时器ID
	int				ModetoStart;			//将要开启的游戏模式
	int				ModeButtonStatus;				//将要开启的游戏模式的按钮的样式
	QMyButton		*StartGame_Adventure;	//冒险模式按钮
	QMyButton		*StartGame_NetFight;	//冒险模式按钮
	QMyButton		*Options;				//选项按钮
	QMyButton		*Help;					//帮助按钮
	QMyButton		*Quit;					//退出按钮
	QMyObject		*Name_Card;				//姓名牌
	QMyButton		*Name_Change;			//改姓名
	QMyObject		*zombieHand;			//开场僵尸的手
	QSignalMapper	*Mapper;				//信号地图

public:
	QGameMainMode(QGameModeLoader* parent = 0);
	~QGameMainMode();

signals:
	//开启某种游戏模式
	void NewGameStart(int);
	//帮助开始
	void Help_Start();
	//设置启动
	void Setting_Options();

public slots:
	//开启某种游戏模式与动画
	void beforeNewGameStart(int);

public:
	void timerEvent(QTimerEvent* event);
	//计时器事件

};

class QGameAdventureMode :public QGameMode
{
	Q_OBJECT
private:
	int						currentTime;				//计时器时间
	int						currentGame;				//当前关卡
	int						stage;						//游戏阶段
	int						TimerID;					//计时器ID
	int						barMoveed;					//滚动条是否已经移动
	bool					firstZombieShowed;			//第一只僵尸是否已经出现
	qint32					Level;						//当前关卡
	QFile					SettingsFile;				//配置文件
	QMySunShine				*newSunShine;				//创建新阳光的指针
	QPropertyAnimation		*animation;					//动画
	QCardSelector			*Selector;					//卡片选择器
	QCardBank				*Bank;						//卡片商
	QMyShovel				*Shovel;					//铲子
	QMyObject				*Shovel_Bank;				//铲子槽
	QMyProcessor			*MyProcessorBar;			//进度条
	QMyMap					*MappingSystem;				//地图处理
	QMyButton				*QuitGame;					//退出按鈕
	int						totCards;					//可选卡片的种类数
	QVector<objectNames>	CardList;					//可选卡片的种类，之后改写为文件读取
	qint32					totZombies;					//总共的僵尸数量，可以改为文件读取
	QVector<Node>			ZombiesList;				//僵尸名字和出现的时间，可以修改外接文件

public:
	QGameAdventureMode(QGameModeLoader *parent = 0);
	~QGameAdventureMode();

public slots:
	//游戏开始
	void GameStart();

public:
	//计时器时间
	void timerEvent(QTimerEvent *event);
	//移动View的滚动条
	void moveScrollBar(int fromvalue, int arrivevalue, int duration);
	//将读取的僵尸数字转化为对应的枚举类型
	objectNames zombieTypeInttoEnum(int);
	//将读取的植物数字转化为对应的枚举类型
	objectNames plantTypeInttoEnum(int);
};