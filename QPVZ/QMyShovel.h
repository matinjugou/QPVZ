#pragma once
#include "QMyObject.h"

class QMyShovel :public QMyObject
{
	Q_OBJECT
protected:
	QPointF		OriginPos;			//用来记录铲子的原始位置
	bool		status;				//当前状态，拿起或者放下
public:
	QMyShovel(QGameAdventureMode *parent = 0);
	QMyShovel(int x, int y, QGameAdventureMode *parent = 0);
	QMyShovel(QGameNetFightMode *parent = 0);
	QMyShovel(int x, int y, QGameNetFightMode *parent = 0);
	~QMyShovel();
signals:
	//左键点击
	void leftButtonClicked(QPointF);
public:
	//设置原始位置
	void setOriginPos(QPointF);
	//鼠标点击事件
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	//鼠标移动事件
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
};