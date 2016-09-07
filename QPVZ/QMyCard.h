#pragma once
#include "QMyObject.h"
#include "MyVariable.h"

//#include "QGameMode.h"

enum cardType{chosen, unchosen, inGame};
class QMyCard :public QMyObject
{
	Q_OBJECT
	Q_PROPERTY(QPointF pos READ pos WRITE setPos)
protected:
	int					Sunprice;			//阳光值
	int					CD;					//种植冷却时间
	bool				inCD;				//是否正在冷却中
	int					currentTime;		//时间处理器现在的时间
	QString				nameText;			//卡片的花费说明文字
	cardType			chosenType;			//卡片的状态，是否被选择用于参战，是否已经游戏开始
	objectNames			objectTypeName;		//卡片对应的植物名称
	QPointF				cardPosinSelector;  //存储放在卡片选择器中的位置，便于回移
	QGraphicsRectItem	CardCover;			//用于表示冷却时间的阴影遮盖
public:
	QMyCard(QCardSelector *parent = 0);
	~QMyCard();

signals:
	void moveToBank(QMyCard*);
	//发送消息要求移动到银行
	void moveToSelector(QMyCard*);
	//发送消息要求移动到选择器
	void ReadytoPlant(objectNames, QPointF, QMyCard*);
	//发送准备种植的消息

public slots:
	void moveAccepted(QPointF);
	//移动到Bank的移动请求被接受

public:
	int getSunPrice();
	//得到阳关值
	bool getInCD();
	//得到冷却时间
	void CDStart();
	//开始冷却
	void timerEvent(QTimerEvent *event);
	//时间响应事件
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	//鼠标点击事件
	void setChosenType(cardType);
	//设置当前卡片状态
	void setCardOriginPos(QPointF);
	//设置卡片在卡片选择器里面的位置
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	//绘制函数
};

//TODO 继承并构造卡片子类

class PeaShooterCard :public QMyCard
{
public:
	PeaShooterCard(QCardSelector *parent = 0);
	~PeaShooterCard();
};

class SunFlowerCard :public QMyCard
{
public:
	SunFlowerCard(QCardSelector *parent = 0);
	~SunFlowerCard();
};

class WallNutCard :public QMyCard
{
public:
	WallNutCard(QCardSelector *parent = 0);
	~WallNutCard();
};

class CommonZombieCard :public QMyCard
{
public:
	CommonZombieCard(QCardSelector *parent = 0);
	~CommonZombieCard();
}; 

class BucketHeadZombieCard :public QMyCard
{
public:
	BucketHeadZombieCard(QCardSelector *parent = 0);
	~BucketHeadZombieCard();
};

class PoleVaultingZombieCard :public QMyCard
{
public:
	PoleVaultingZombieCard(QCardSelector *parent = 0);
	~PoleVaultingZombieCard();
};