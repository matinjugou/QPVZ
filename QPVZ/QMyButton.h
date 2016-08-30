#pragma once
#include <QtGui>
#include <qgraphicsitem.h>

class QMyButton :public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT
private:
	QPixmap Button_Plain;
	QPixmap Button_Hover;
public:
	QMyButton(QGraphicsItem *parent = 0);
	QMyButton(const QString &filename, const QString &filenameHover, QGraphicsItem *parent = 0);
	~QMyButton();
signals:
	void clicked();
public:
	void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
	void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
public:
	void setPlainImg(const QString &filename);
	void setHoverImg(const QString &filename);
};