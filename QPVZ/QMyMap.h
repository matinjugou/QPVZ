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
	int						debugweek = 0;			//等待删除
	QGraphicsTextItem		QStatusString;			//调试用信息，等待删除

	QGraphicsScene			*Mapscene;				//mode的scene,重建对象树系统之后可以删掉
	bool					isPlantedMap[12][5];	//初始化为全false
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
	void addItem(objectNames, QPointF);
	//向scene中加一个物品
	void RequestDone();
	//发送种植请求处理完毕的消息

public slots:
	void Plantrequest_Ready(objectNames, QPointF);
	//尝试种植
	void Plantrequest_Update(QPointF);
	//更新显示将要种植位置的物品的位置
	void Plantrequest_Try();
	//尝试种植
	void Plantrequest_Done();
	//种植完成

	void Itemadded(QMyObject*);
	//接受来自displayer的物品添加完成的消息
	void addtoMap(objectType, QMyObject*);
	//将新创建的植物、僵尸、武器加入地图的管理序列中
	void removefromMap(objectType, QMyObject*);
	//将植物、僵尸、武器从地图的管理序列中去除

public:
	QMyMap(QGameMode *parent = 0);
	~QMyMap();

public:

	void changePixmap(objectNames);
	//将鼠标跟随的物品和用于显示位置的物品的图片转化成对应植物的
	void timerEvent(QTimerEvent *event);
	//时间响应事件
	void examineMap();
	//检查地图上的冲突事件
	
	qreal getVerticalLine(int i);
	//得到竖直边界线的scene位置
	qreal getHorizontalLine(int i);
	//得到水平边界线的scene位置
	QPoint PostoPoint(QPointF);
	//将scene中的位置点转化为地图的坐标点
	QPointF PointtoPos(QPoint);
	//将地图的坐标点转化为scene中的位置点
	QRectF getRect();
	//获得地图的范围
	
	void setScene(QGraphicsScene* scene);
	//设置map的scene，后期可以利用对象树删除
};