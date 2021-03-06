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
	QPixmap			ShadePixmap;		//待种植的植物图片
	objectNames		objectTypeNames;	//待种植的植物的名字
	objectType		objectType;			//种植的物品的种类
	QPoint			PointinMap;			//待种植的植物在地图上的坐标点
public:
	QItemShade(QMyMap *parent = 0);
	~QItemShade();

signals:
	//左键被点击
	void leftButtonClicked();
	//右键被点击
	void rightButtonClicked();
	//鼠标移动
	void cursorMoved(QPointF);

public:
	//得到待种植植物在地图上的坐标点
	QPoint getPointinMap();
	//鼠标移动事件
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
	//鼠标点击事件
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	//加载图片
	void LoadPixmap(const QString &filename);
	//设置待种植植物在地图上的坐标点
	void setPointinMap(QPoint temppoint);
};