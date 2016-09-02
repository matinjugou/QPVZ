#pragma once
#include "QMyCard.h"

class QCardBank :public QObject, public QGraphicsItemGroup
{
	Q_OBJECT
private:
	int statusType; //0 presen out of game, 1 pres in game
	int sunshineNum;
	QGraphicsPixmapItem *Board;
	QGraphicsTextItem *sunshineText;
	QMyCard* cardList[8];
	QMyCard* cardReadytoPlant;
	int totCard;
public:
	QCardBank(QWidget *parent = 0);
	~QCardBank();
signals:
	void moveAccepted(QPointF, QMyCard*); //�����������󲢻ش�λ�ø���Ƭ,position��QPointF֮����Ҫͳһ
	void ReadytoPlant(objectNames, QPointF);
public slots:
	void plantRequestDone();
	void moveRequested(QMyCard*);	//���տ�Ƭ���������󣬲��õ���ַ���ڻش�
	void removeConfirm(QMyCard*);
	void ReadytoPlantFromCard(objectNames, QPointF, QMyCard*);
	void Initconnection();
};