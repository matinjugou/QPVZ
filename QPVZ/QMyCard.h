#pragma once
#include "QMyObject.h"
//#include "QGameMode.h"

enum cardType{chosen, unchosen, inGame};
class QMyCard :public QMyObject
{
	Q_OBJECT
	Q_PROPERTY(QPointF pos READ pos WRITE setPos)
protected:
	int Sunprice;
	int CD;
	bool inCD;
	int currentTime;
	cardType chosenType;
	QString nameText;
	objectNames objectTypeName;
	QPointF cardPosinSelector;  //�洢���ڿ�Ƭѡ�����е�λ�ã����ڻ���
	QGraphicsRectItem CardCover;
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
	void CDStart();
	void timerEvent(QTimerEvent *event);
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	void setChosenType(cardType);
	void setCardOriginPos(QPointF);
	int getSunPrice()
	{
		return Sunprice;
	}
	bool getInCD()
	{
		return inCD;
	}
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

//TODO �̳в����쿨Ƭ����

class PeaShooterCard :public QMyCard
{
public:
	PeaShooterCard(QWidget *parent = 0);
	~PeaShooterCard();
};