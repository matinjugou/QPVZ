#pragma once
#include "QMyObject.h"
#include "QItemShades.h"
#include "QPlants.h"
#include "QZombies.h"
#include "QWeapons.h"
#include "QGameMode.h"
#include "MyVariable.h"

class QItemShade;

class QMyMap :public QMyObject
{
	Q_OBJECT
private:
	bool					isPlantedMap[12][5];	//是否种植
	QMyObject				*objectPointMap[12][5];	//在此处种植的物品指针
	QRectF					MapRect;				//地图区域
	QPoint					pointNewItemtoPlantOn;	//记录一下新的植物要放置的地点
	qreal					verticalLines[12];		//竖直边界线
	qreal					horizontalLines[5];		//水平边界线
	QItemShade				*ReadytoPlant;			//尝试种植时跟随鼠标移动的物品
	QItemShade				*ReadytoPlant_Shadow;	//尝试种植时显示将要种下的位置的物品
	QVector<QPlants*>		PlantsinMap;			//植物数组
	QVector<QZombies*>		ZombiesinMap;			//僵尸数组
	QVector<QWeapons*>		WeaponsinMap;			//子弹数组

signals:
	//向scene中加一个物品
	void addItem(objectNames, QPointF);
	//发送种植请求处理完毕的消息
	void RequestDone();
	//发送种植请求处理取消的消息
	void RequestCancelled();
	//地图上的阳光被捡起
	void SunShineAdded();

public slots:
	//尝试种植
	void Plantrequest_Ready(objectNames, QPointF);
	//更新显示将要种植位置的物品的位置
	void Plantrequest_Update(QPointF);
	//尝试种植
	void Plantrequest_Try();
	//种植完成
	void Plantrequest_Done();
	//种植取消
	void Plantrequest_Cancelled();

	//接受来自displayer的物品添加完成的消息
	void Itemadded(QMyObject*);
	//将新创建的植物、僵尸、武器加入地图的管理序列中
	void addtoMap(objectType, QMyObject*);
	//将植物、僵尸、武器从地图的管理序列中去除
	void removefromMap(objectType, QMyObject*);

	//接收铲子消息
	void ShovelMessage(QPointF);

public:
	QMyMap(QGameMode *parent = 0);
	~QMyMap();

public:

	//将鼠标跟随的物品和用于显示位置的物品的图片转化成对应植物的
	void changePixmap(objectNames);
	//时间响应事件
	void timerEvent(QTimerEvent *event);
	//检查地图上的冲突事件
	void examineMap();
	
	//得到竖直边界线的scene位置
	qreal getVerticalLine(int i);
	//得到水平边界线的scene位置
	qreal getHorizontalLine(int i);
	//将scene中的位置点转化为地图的坐标点
	QPoint PostoPoint(QPointF);
	//将地图的坐标点转化为scene中的位置点
	QPointF PointtoPos(QPoint);
	//获得地图的范围
	QRectF getRect();
};