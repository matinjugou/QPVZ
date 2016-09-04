#pragma once
#include "qgraphicsitem.h"
#include "QtWidgets"
#include "QMyObject.h"

class QItemShade :public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT
public:
	QPixmap ShadePixmap;
	objectNames objectTypeNames;
	QPoint PointinMap;
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
	void LoadPixmap(const QString &filename);
	QPoint getPointinMap()
	{
		return PointinMap;
	}
	void setPointinMap(QPoint temppoint)
	{
		PointinMap = temppoint;
	}
};