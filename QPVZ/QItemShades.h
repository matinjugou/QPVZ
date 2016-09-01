#pragma once
#include "qgraphicsitem.h"
#include "QtWidgets"

class QItemShade :public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT
public:
	QPixmap ShadePixmap;
public:
	QItemShade(QWidget *parent = 0);
	~QItemShade();
signals:
	void leftButtonClicked();
	void rightButtonClicked();
public:
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
};