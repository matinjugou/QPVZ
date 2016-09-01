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
	void moveAccepted(Position, QMyCard*); //�����������󲢻ش�λ�ø���Ƭ,position��QPointF֮����Ҫͳһ
	void ReadytoPlant(objectNames, QPointF);
public slots:
	void moveRequested(QMyCard*);	//���տ�Ƭ���������󣬲��õ���ַ���ڻش�
	void removeConfirm(QMyCard*);
public:
	void Initconnection();
};