#pragma once
#include "QMyCard.h"

class QCardBank :public QObject, public QGraphicsItemGroup
{
	Q_OBJECT
private:
	int statusType; //0 presen out of game, 1 pres in game
	QGraphicsPixmapItem *Board;
	QMyCard* cardList[8];
	int totCard;
public:
	QCardBank(QWidget *parent = 0);
	~QCardBank();
signals:
	void moveAccepted(Position, QMyCard*); //接受置入请求并回传位置给卡片,position与QPointF之后需要统一
	void ReadytoPlant(objectNames, QPointF);
public slots:
	void moveRequested(QMyCard*);	//接收卡片的置入请求，并得到地址便于回传
	void removeConfirm(QMyCard*);
public:
	void Initconnection();
};