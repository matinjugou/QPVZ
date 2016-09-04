#pragma once
#include "QMyObject.h"

class QMySunShine :public QMyObject
{
	Q_OBJECT
	Q_PROPERTY(QPointF pos READ pos WRITE setPos)
	Q_PROPERTY(qreal scale READ scale WRITE setScale)
protected:
	bool beTaken;
	int currentTime;
	QPropertyAnimation *Scaleanimation;
public:
	QMySunShine(QWidget *parent = 0);
	~QMySunShine();
signals:
	void BeTaken();
public:
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	void timerEvent(QTimerEvent *event);
	void SetScaleAnimation(qreal fromScale, qreal toScale, int duration);
};