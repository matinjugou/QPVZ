#pragma once
#include "QMyObject.h"

class QMyMap :public QMyObject
{
private:
	QMyObject *Map[5][5];	//��ʼ��Ϊȫ��Ϊ��ָ��
	bool isPlantedMap[5][5];		//��ʼ��Ϊȫfalse
	QRectF MapRect;
	qreal verticalLines[5];		//��ֱ�߽���
	qreal horizontalLines[5];	//ˮƽ�߽���
	QGraphicsPixmapItem *ReadytoPlant;
signals:
	void RequestAccepted();		//��������
	void RequestDinied();		//�ܾ�����
	void deleteFromMap(QPointF);//ɾ��һ����Ʒ
public slots:
	void Plantrequest_Ready(objectNames, QPointF); //������ֲ
public:
	QMyMap(QWidget *parent = 0);
	~QMyMap();
public:
	QPoint PostoPoint(QPointF);
	QPointF PointtoPos(QPoint);
	void changePixmap(objectNames);
};