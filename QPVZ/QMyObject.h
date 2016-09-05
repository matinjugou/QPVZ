 #pragma once
#include <QtWidgets>
#include <QtGui>
#include "qgraphicsitem.h"
#include "qgraphicsscene.h"
#include "qvector.h"
#include "MyVariable.h"



class QGameMode;
class QCardBank;
class QCardSelector;
class QPlants;
class QZombies;
class QWeapons;
class QEquipments;
class QFightMethods;
class QMySunShine;

class QMyObject :public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT
	Q_PROPERTY(QPointF pos READ pos WRITE setPos)
protected:
	int						TimerID;		//计时器ID
	int						HP;				//血量
	int						GifNumber;		//要播放的GIF的编号
	int						isDead;			//是否死亡
	QVector<QPixmap>		Pictures;		//图片数组
	QVector<QMovie*>		Gifs;			//GIF数组
	QMovie					myGif;			//GIF
	objectType				objectTypeName; //物品种类
	QPropertyAnimation		*animation;		//动画
	QPoint					PointinMap;		//物品在地图上的位置

public:
	QMyObject(QObject *parent = 0);
	QMyObject(QGameMode *parent = 0);
	QMyObject(QCardBank *parent = 0);
	QMyObject(QCardSelector *parent = 0);
	QMyObject(QPlants *parent = 0);
	QMyObject(QZombies *parent = 0);
	QMyObject(QGraphicsScene *parent = 0);
	~QMyObject();

signals:

	//将自己加入地图处理事件
	void addtomap(objectType, QMyObject*);
	//将自己从地图中移除
	void removefrommap(objectType, QMyObject*);

public slots:
	//移动动画
	void moveTo(int x, int y, int duration);
	//移动动画
	void moveTo(int x, int y, int duration, QEasingCurve::Type type);
	//移动动画
	void moveTo(QPointF targetPos, int duration);
	//移动动画
	void moveTo(QPointF targetPos, int duration, QEasingCurve::Type type);
	//播放GIf时切换帧
	void setnewPixmap();
	//播放GIF时切换帧
	void setnewPixmap(int);

public:
	//得到当前生命值
	int getHP();
	//得到图片数组中对应的图片
	QPixmap getPicture(int i);
	//得到物品的种类
	objectType getType();
	//得到物品在地图上的坐标
	QPoint getPointinMap();
	//设置物品在地图内的坐标
	void setPointinMap(int x, int y);
	//设置物品在地图内的坐标
	void setPointinMap(QPoint);
	//设置生命值
	void setHP(int);
	//减少生命值
	void killHP(int);
	//设置物品的种类
	void setType(objectType Typename);
	//存入新的图片
	void pushbackPixmap(QPixmap);
	//播放GIF动画时候切换帧数
	void setMyPixmap(int);
	//设置播放对应的GIF
	void setMyGif(int);
	//死亡动画
	virtual void Died(){}
};
