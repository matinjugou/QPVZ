#pragma once
#include "QMyObject.h"
#include "MyVariable.h"

class QMySunShine :public QMyObject
{
	Q_OBJECT
	Q_PROPERTY(QPointF pos READ pos WRITE setPos)
	Q_PROPERTY(qreal scale READ scale WRITE setScale)
protected:
	bool				beTaken;			//阳关是否已经被拾取
	int					currentTime;		//当前计时器时间
	QPropertyAnimation	*Scaleanimation;	//缩放动画

public:
	QMySunShine(QGraphicsScene *parent = 0);
	~QMySunShine();

signals:
	//发送阳光被取走的信号
	void BeTaken();

public:
	//鼠标点击事件
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	//计时器事件
	void timerEvent(QTimerEvent *event);
	//缩放动画
	void SetScaleAnimation(qreal fromScale, qreal toScale, int duration);
};