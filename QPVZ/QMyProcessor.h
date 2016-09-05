#pragma once
#include "qgraphicsitem.h"
#include "qwidget.h"

class QGameAdventureMode;

class QMyProcessor:public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT
protected:
	qreal					totProcess;			//满值
	qreal					currentProcess;		//当前值
	QVector<int>			breakPoints;		//高潮点
	QPixmap					FlagPix;		//僵尸头图像
	QGraphicsPixmapItem		boardUpper;			//上层板
	QGraphicsPixmapItem		boardBelow;			//底层板
	QGraphicsPixmapItem		ZombieHead;			//僵尸头
	QGraphicsPixmapItem		*Flag;				//旗帜
public:
	QMyProcessor(QGameAdventureMode *parent = 0);
	QMyProcessor(qreal totprocess, qreal currentprocess, const QVector<int> &breakpoints,
		QGameAdventureMode *parent = 0);
	~QMyProcessor();
public:
	//初始化
	void Init();
	//设置满值
	void settotProcess(qreal totprocess);
	//设置当前值
	void setcurrentProcess(qreal currentprocess);
	//设置断点
	void setbreakPoints(const QVector<int> &breakpoints);

	//计时器事件
	void timerEvent(QTimerEvent *event);
};