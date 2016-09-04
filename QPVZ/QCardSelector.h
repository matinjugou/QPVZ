#pragma once
#include "QMyCard.h"
#include "QMyButton.h"

class QCardSelector :public QObject, public QGraphicsItemGroup
{
	Q_OBJECT
	Q_PROPERTY(QPointF pos READ pos WRITE setPos)
private:
	QGraphicsPixmapItem* Board;
	QMyCard* newCard;
	QMyCard* newCardBoard;
	QPoint currentPos;		//记录当前绘画卡片的坐标点
	QMyButton* startGame;
	QPropertyAnimation *animation;
	int totCard;
	int maxX;
	int maxY;
signals:
	void moveRequest(QMyCard*);
	void removeInform(QMyCard*);
	void startGameNow();
public slots:
	void moveAccepted(QPointF, QMyCard*);
	void resetIn(QMyCard*);
public:
	void moveTo(int x, int y, int duration);
	void moveTo(QPointF targetPos, int duration);
	QCardSelector(QWidget *parent = 0);
	QCardSelector(int totcard, const objectNames cardlist[], QWidget *parent = 0);
	~QCardSelector();
public:
	void addNewCard(objectNames);
};