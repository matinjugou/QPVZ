#pragma once
#include "QMyCard.h"
#include "MyVariable.h"

class QCardBank :public QObject, public QGraphicsItemGroup
{
	Q_OBJECT
	Q_PROPERTY(QPointF pos READ pos WRITE setPos)
private:
	int sunshineNum;
	QGraphicsPixmapItem		*Board;
	QGraphicsTextItem		*sunshineText;
	QPropertyAnimation		*animation;
	QMyCard					*cardList[8];
	QMyCard					*cardReadytoPlant;
	int						totCard;

public:
	QCardBank(QGameMode *parent = 0);
	~QCardBank();

signals:
	void moveAccepted(QPointF, QMyCard*);		
	//接受Selector中卡片的置入请求并回传位置给卡片
	void ReadytoPlant(objectNames, QPointF);	
	//向map发送准备种植的消息

public slots:
	//接收卡片的置入请求，并得到卡片地址便于回传
	void moveRequested(QMyCard*);				
	//接收卡片的离开请求，并得到卡片的地址便于从group中除去
	void removeConfirm(QMyCard*);				
	
	//初始化卡槽内所有卡片和bank之间用来种植新植物的连接
	void Initconnection();						
	
	//接受从卡片传来的准备种植的消息，处理后传给map用于种植
	void ReadytoPlantFromCard(objectNames, QPointF, QMyCard*);
	//种植请求处理完毕
	void plantRequestDone();
	//种植请求处理取消
	void plantRequestCancelled();
	
	//增加阳光值
	void SunShineAdded();
	//设定阳光值
	void setSunShine(int);

public:
	void moveTo(int x, int y, int duration);
	void moveTo(QPointF targetPos, int duration);
	void timerEvent(QTimerEvent *event);

};