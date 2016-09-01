#pragma once
#include "qgraphicsitem.h"
#include "QtWidgets"

class QItemShade :public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT
public:
	QPixmap ShadePixmap;
	objectNames objectTypeNames;
public:
	QItemShade(QWidget *parent = 0);
	~QItemShade();
signals:
	void leftButtonClicked();
	void rightButtonClicked();
	void cursorMoved(QPointF);
public:
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
};