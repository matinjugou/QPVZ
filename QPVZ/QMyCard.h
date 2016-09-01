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
	QPointF cardPosinSelector;  //�洢���ڿ�Ƭѡ�����е�λ�ã����ڻ���
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

//TODO �̳в����쿨Ƭ����