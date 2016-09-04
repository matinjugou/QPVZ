#pragma once
#include "qgraphicsview.h"
#include "qgraphicsscene.h"
#include "QMyObject.h"
#include "MyVariable.h"


class QGameDisplayer:public QObject
{
	Q_OBJECT
private:
	QGraphicsView		*mainView;		//主视图
	QGraphicsScene		*currentScene;	//当前视图

public:
	QGameDisplayer(QObject* parent = 0);
	QGameDisplayer(QGraphicsScene *scene, QObject* parent = 0);
	~QGameDisplayer();

signals:
	void Itemadded(QMyObject*);
	//向下传递物品已经添加的信号

public slots:
	void setScene(QGraphicsScene* scene);
	//设置当前的场景
	void addItem(objectNames, QPointF);
	//添加物品到场景

public:
	QGraphicsView* getView();
	//得到当前的视图
	QGraphicsScene* getCurrentScene();
	//得到当前的场景
};