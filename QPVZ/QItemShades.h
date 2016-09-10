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
	//��������
	void leftButtonClicked();
	//�Ҽ������
	void rightButtonClicked();
	//����ƶ�
	void cursorMoved(QPointF);

public:
	//�õ�����ֲֲ���ڵ�ͼ�ϵ������
	QPoint getPointinMap();
	//����ƶ��¼�
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
	//������¼�
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	//����ͼƬ
	void LoadPixmap(const QString &filename);
	//���ô���ֲֲ���ڵ�ͼ�ϵ������
	void setPointinMap(QPoint temppoint);
};