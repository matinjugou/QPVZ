#pragma once
#include "qgraphicsitem.h"
#include "QtWidgets"
#include "QMyObject.h"
#include "MyVariable.h"

class QMyMap;

class QItemShade :public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT
public:
	QPixmap			ShadePixmap;		//����ֲ��ֲ��ͼƬ
	objectNames		objectTypeNames;	//����ֲ��ֲ�������
	objectType		objectType;			//��ֲ����Ʒ������
	QPoint			PointinMap;			//����ֲ��ֲ���ڵ�ͼ�ϵ������
public:
	QItemShade(QMyMap *parent = 0);
	~QItemShade();

signals:
	void leftButtonClicked();
	//��������
	void rightButtonClicked();
	//�Ҽ������
	void cursorMoved(QPointF);
	//����ƶ�

public:
	QPoint getPointinMap();
	//�õ�����ֲֲ���ڵ�ͼ�ϵ������
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
	//����ƶ��¼�
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	//������¼�
	void LoadPixmap(const QString &filename);
	//����ͼƬ
	void setPointinMap(QPoint temppoint);
	//���ô���ֲֲ���ڵ�ͼ�ϵ������
};