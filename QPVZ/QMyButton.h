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
	QPixmap		Button_Plain;	//��ťû�б��ڸ�ʱ��ͼƬ
	QPixmap		Button_Hover;	//��ť���ڸ�ʱ���ͼƬ
	int			PosX;			//��¼��ť�ĳ�ʼλ�ã���������ť�����ʱ��Ĳ���
	int			PosY;			//��¼��ť�ĳ�ʼλ�ã���������ť�����ʱ��Ĳ���
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