#pragma once
#include <QtGui>
#include <qgraphicsitem.h>
#include "MyVariable.h"

class QGameMode;
class QCardSelector;

class QMyButton :public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT
	Q_PROPERTY(QPointF pos READ pos WRITE setPos)
private:
	QPixmap		Button_Plain;	//按钮没有被遮盖时的图片
	QPixmap		Button_Hover;	//按钮被遮盖时候的图片
	int			PosX;			//记录按钮的初始位置，用来处理按钮被点击时候的颤动
	int			PosY;			//记录按钮的初始位置，用来处理按钮被点击时候的颤动
public:
	QMyButton(QGameMode *parent = 0);
	QMyButton(QCardSelector *parent = 0);
	QMyButton(const QString &filename, const QString &filenameHover, QGameMode *parent = 0);
	QMyButton(const QString &filename, const QString &filenameHover, QCardSelector *parent = 0);
	~QMyButton();
signals:
	void clicked();
public:
	void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
	void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
public:
	void setPlainImg(const QString &filename);
	void setHoverImg(const QString &filename);
};