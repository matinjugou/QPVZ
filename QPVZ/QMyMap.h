#pragma once
#include "QMyObject.h"
#include "QItemShades.h"

class QMyMap :public QMyObject
{
private:
	QMyObject *Map[5][5];	//初始化为全部为空指针
	bool isPlantedMap[5][5];		//初始化为全false
	QRectF MapRect;
	qreal verticalLines[5];		//竖直边界线
	qreal horizontalLines[5];	//水平边界线
	QItemShade *ReadytoPlant;
	QItemShade *ReadytoPlant_Shadow;
signals:
	void RequestAccepted(objectNames, Position);		//接收请求
	void RequestDinied();		//拒绝请求
	void RequesCancelled();
	void deleteFromMap(QPointF);//删除一个物品
public slots:
	void Plantrequest_Ready(objectNames, QPointF); //尝试种植
public:
	QMyMap(QWidget *parent = 0);
	~QMyMap();
public:
	QPoint PostoPoint(QPointF);
	QPointF PointtoPos(QPoint);
	void changePixmap(objectNames);
};