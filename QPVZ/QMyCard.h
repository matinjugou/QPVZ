#pragma once
#include "QMyObject.h"
//#include "QGameMode.h"

enum cardType{chosen, unchosen, inGame};
class QMyCard :public QMyObject
{
protected:
	cardType chosenType;
	QString nameText;
	objectNames objectTypeName;
	QPointF cardPosinSelector;  //存储放在卡片选择器中的位置，便于回移
public:
	QMyCard(QWidget *parent = 0);
	~QMyCard();
signals:
	void moveToSelector(QMyCard*);
	void moveToBank(QMyCard*);
	void ReadytoPlant(objectNames, QPointF, QMyCard*);
public slots:
	void moveAccepted(QPointF);
public:
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	void setChosenType(cardType);
};

//TODO 继承并构造卡片子类