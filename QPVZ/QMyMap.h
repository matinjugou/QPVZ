#pragma once
#include "QMyObject.h"
#include "QItemShades.h"
#include "QPlants.h"
#include "QZombies.h"

class QMyMap :public QMyObject
{
private:
	QMyObject *Map[5][5];	//��ʼ��Ϊȫ��Ϊ��ָ��
	bool isPlantedMap[5][5];		//��ʼ��Ϊȫfalse
	QRectF MapRect;
	QPoint pointNewItemtoPlantOn;
	qreal verticalLines[5];		//��ֱ�߽���
	qreal horizontalLines[5];	//ˮƽ�߽���
	QItemShade *ReadytoPlant;
	QItemShade *ReadytoPlant_Shadow;
	QVector<QPlants*> PlantsinMap;
	QVector<QZombies*> ZombiesinMap;
signals:
	void RequestDone();
	void deleteFromMap(QPointF);//ɾ��һ����Ʒ
	void addItem(objectNames, QPointF);	//��scene�м�һ����Ʒ
public slots:
	void Plantrequest_Ready(objectNames, QPointF); //������ֲ
	void Plantrequest_Update(QPointF);
	void Plantrequest_Try();
	void Plantrequest_Done();
	void Itemadded(QMyObject*);
public:
	QMyMap(QWidget *parent = 0);
	~QMyMap();
public:
	QPoint PostoPoint(QPointF);
	QPointF PointtoPos(QPoint);
	void changePixmap(objectNames);
	void timerEvent(QTimerEvent *event);
	void examineMap();
};