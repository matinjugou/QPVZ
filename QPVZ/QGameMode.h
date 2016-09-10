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
	QGraphicsScene		*Scene;					//场景
	QGraphicsView		*View;					//视图
	QMyObject			*Background;			//背景
	QMediaPlayer		*backgroundMusic;		//BGM

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
	//重新播放BGM
	void replayBGM(QMediaPlayer::State);
};

class QGameMainMode :public QGameMode
{
	Q_OBJECT
private:
	int				currentTime;			//当前时间
	int				TimerID;				//计时器ID
	int				ModetoStart;			//将要开启的游戏模式
	int				ModeButtonStatus;		//将要开启的游戏模式的按钮的样式
	QMyButton		*StartGame_Adventure;	//冒险模式按钮
	QMyButton		*StartGame_NetFight;	//冒险模式按钮
	QMyButton		*Options;				//选项按钮
	QMyButton		*Help;					//帮助按钮
	QMyButton		*Quit;					//退出按钮
	QMyObject		*Name_Card;				//姓名牌
	QMyButton		*Name_Change;			//改姓名
	QMyObject		*zombieHand;			//开场僵尸的手
	QSignalMapper	*Mapper;				//信号地图
	QMediaPlayer	*eveilLaugh;			//僵尸手伸出来的音效
	QMediaPlayer	*gameStartSound;		//僵尸手伸出来的音效

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
	int						GameOverTiemerCount;		//游戏失败退出倒计时
	int						GameOverTiemerID;			//游戏失败计时器
	bool					isGameOvered;				//游戏是否结束了
	bool					Gamewin1;					//胜利条件一，是否所有僵尸都死了
	bool					Gamewin2;					//胜利条件二，是否还有僵尸没有上场
	QMyObject				*GameOverPix;				//游戏失败画面
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
	qint32					totZombies;					//总共的僵尸数量，可以改为文件读取
	QVector<Node>			ZombiesList;				//僵尸名字和出现的时间，可以修改外接文件
	int						totCards;					//可选卡片的种类数
	QVector<objectNames>	CardList;					//可选卡片的种类，之后改写为文件读取
	int						readyToPlantCount;			//准备安放植物图片数量
	QMediaPlayer			*readyToPlantBGM;			//准备安放植物的音效
	QMyObject				*readyToPlantText;			//准备安放植物提示

public:
	QGameAdventureMode(QGameModeLoader *parent = 0);
	~QGameAdventureMode();

public slots:
	//游戏开始
	void GameStart();
	//游戏结束
	void GameOver();
	//游戏胜利条件一改变
	void GameConditionChanged(bool);

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

class QGameNetFightMode :public QGameMode
{
	Q_OBJECT
private:
	bool					asServer;					//是否作为服务器
	QString					ipStr;						//IP地址
	int						currentTime;				//计时器时间
	int						TimerID;					//计时器ID
	int						stage;						//游戏状态
	int						barMoveed;					//滚动条是否已经移动
	int						timeCouner;					//植物胜利计时器
	QMyObject				*ZombieLine;				//僵尸的种植边界线
	qint32					Level;						//当前关卡
	QFile					SettingsFile;				//配置文件
	QMySunShine				*newSunShine;				//创建新阳光的指针
	QPropertyAnimation		*animation;					//动画
	QCardSelector			*Selector;					//卡片选择器
	QCardBank				*Bank;						//卡片商
	QMyMap					*MappingSystem;				//地图处理
	QMyButton				*QuitGame;					//退出按鈕
	QTcpServer				*Server;					//服务器
	QTcpSocket				*Socket;					//套接字
	QMyDialog				*myDialog;					//对话框
	int						totCards;					//可选卡片的种类数
	QVector<objectNames>	CardList;					//可选卡片的种类，之后改写为文件读取
	int						readyToPlantCount;			//准备安放植物图片数量
	QMediaPlayer			*readyToPlantBGM;			//准备安放植物的音效
	QMyObject				*readyToPlantText;			//准备安放植物提示

public:
	QGameNetFightMode(QGameModeLoader* parent = 0);
	~QGameNetFightMode();

public slots:
	//游戏开始
	void GameStart();
	//收到种下新物品的消息
	void getMessage();
	//发送种下新物品的消息
	void sendMessage(objectNames, QPointF);

public:
	//初始化连接
	bool InitTcpConnection();
	//加载卡片资源
	void LoadMyCard();
	//加载种植事件处理
	void InitAddItemConnection();
	//计时器事件
	void timerEvent(QTimerEvent *event);
	//移动View的滚动条
	void moveScrollBar(int fromvalue, int arrivevalue, int duration);
	//将读取的僵尸数字转化为对应的枚举类型
	objectNames zombieTypeInttoEnum(int);
	//将读取的植物数字转化为对应的枚举类型
	objectNames plantTypeInttoEnum(int);
	//将物品种类名的字符串转化为对应的枚举类型
	objectNames itemStringtoObjectnames(QString);
	//将物品种类名的枚举类型转化为对应的字符串
	QString itemObjectnamestoString(objectNames);
};