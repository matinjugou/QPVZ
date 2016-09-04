#pragma once
#include "QMyCard.h"
#include "QMyButton.h"
#include "MyVariable.h"

class QMyCard;
class QMyButton;
class QGameAdventureMode;

class QCardSelector :public QObject, public QGraphicsItemGroup
{
	Q_OBJECT
	Q_PROPERTY(QPointF pos READ pos WRITE setPos)
private:
	QGraphicsPixmapItem		*Board;			//背景板
	int						maxX;			//横向最大卡片数量
	int						maxY;			//纵向最大卡片数量
	QPoint					currentPos;		//记录当前绘画卡片的坐标点
	int						totCard;		//总卡片数
	QMyCard					*newCard;		//用于创建新卡片的指针
	QMyCard					*newCardBoard;	//用于创建新卡片背景板的指针
	QMyButton				*startGame;		//开始游戏按钮
	QPropertyAnimation		*animation;		//动画

public:
	QCardSelector(QGameMode *parent = 0);
	QCardSelector(QGameAdventureMode *parent = 0);
	QCardSelector(int totcard, const objectNames cardlist[], QGameMode *parent = 0);
	QCardSelector(int totcard, const objectNames cardlist[], QGameAdventureMode *parent = 0);
	~QCardSelector();

signals:
	void moveRequest(QMyCard*);
	//接受来自卡片的移动请求
	void removeInform(QMyCard*);
	//通知Bank将卡片移走
	void startGameNow();
	//通知Mode开始游戏

public slots:
	void moveAccepted(QPointF, QMyCard*);
	//接受来自Bank的确认移动信息，将卡片移到bank内
	void resetIn(QMyCard*);
	//接受来自卡片的将卡片重新放回的消息

public:
	void moveTo(QPointF targetPos, int duration);
	//移动动画
	void moveTo(int x, int y, int duration);
	//移动动画
	void addNewCard(objectNames);
	//添加新的卡片
};