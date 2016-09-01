#pragma once
#include "QMyCard.h"

class QCardSelector :public QObject, public QGraphicsItemGroup
{
	Q_OBJECT
private:
	QGraphicsPixmapItem* Board;
	QMyCard* newCard;
	QGraphicsPixmapItem *newCardBoard;
	Position currentPos;		//记录当前绘画卡片的坐标点
	int totCard;
	int maxX;
	int maxY;
signals:
	void moveRequest(QMyCard*);
	void removeInform(QMyCard*);
public slots:
	void moveAccepted(Position, QMyCard*);
	void resetIn(QMyCard*);
public:
	QCardSelector(QWidget *parent = 0);
	QCardSelector(int totcard, const objectNames cardlist[], QWidget *parent = 0);
	~QCardSelector();
public:
	void addNewCard(objectNames);
};