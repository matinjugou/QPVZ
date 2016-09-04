#pragma once
#include "QMyObject.h"
#include "QItemShades.h"
#include "QPlants.h"
#include "QZombies.h"
#include "QWeapons.h"

class QMyMap :public QMyObject
{
	Q_OBJECT
private:

	int debugweek = 0;

	QGraphicsScene* Mapscene;
	bool isPlantedMap[12][5];		//��ʼ��Ϊȫfalse
	QRectF MapRect;
	QPoint pointNewItemtoPlantOn;
	qreal verticalLines[12];		//��ֱ�߽���
	qreal horizontalLines[5];	//ˮƽ�߽���
	QItemShade *ReadytoPlant;
	QItemShade *ReadytoPlant_Shadow;
	QVector<QPlants*> PlantsinMap;
	QVector<QZombies*> ZombiesinMap;
	QVector<QWeapons*> WeaponsinMap;
	QGraphicsTextItem QStatusString;
signals:
	void RequestDone();
//	void deleteFromMap(QPointF);//ɾ��һ����Ʒ
	void addItem(objectNames, QPointF);	//��scene�м�һ����Ʒ
public slots:
	void Plantrequest_Ready(objectNames, QPointF); //������ֲ
	void Plantrequest_Update(QPointF);
	void Plantrequest_Try();
	void Plantrequest_Done();
	void Itemadded(QMyObject*);
	void addtoMap(objectType, QMyObject*);
	void removefromMap(objectType, QMyObject*);
public:
	QMyMap(QWidget *parent = 0);
	~QMyMap();
public:
	QPoint PostoPoint(QPointF);
	QPointF PointtoPos(QPoint);
	QRectF getRect()
	{
		return MapRect;
	}
	void changePixmap(objectNames);
	void timerEvent(QTimerEvent *event);
	void examineMap();
	qreal getVerticalLine(int i)
	{
		return verticalLines[i];
	}
	qreal getHorizontalLine(int i)
	{
		return horizontalLines[i];
	}

	void setScene(QGraphicsScene* scene)
	{
		Mapscene = scene;
	}
};