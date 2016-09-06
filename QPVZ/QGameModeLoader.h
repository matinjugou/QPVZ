#pragma once
#include "MyVariable.h"
#include "qwidget.h"
#include "qgraphicsscene.h"
#include "qgraphicsview.h"
#include "QGameMode.h"

class QMyObject;

class QGameModeLoader:public QObject
{
	Q_OBJECT
private:
	QGameMainMode	*MainMode;		//游戏的主要模式
	QGameMode		*CurrentMode;	//游戏的当前模式
	QGraphicsView	*LoaderView;	//加载者的视角,引入对象树系统后可以优化掉
public:
	QGameModeLoader(QObject* parent = 0);
	~QGameModeLoader();

signals:
	//传递消息给Displayer切换到某个场景
	void exchangetoScene(QGraphicsScene*);
	//传递消息给Displayer添加物品
	void addItem(objectNames, QPointF);
	//物品添加成功
	void Itemadded(QMyObject*);

public slots:
	//加载游戏模式
	void Load(int);
	//退出当前模式
	void QuitMode();
	//设置视角，引入对象树系统后可以优化掉
	void setView(QGraphicsView*);

public:
	//得到主要游戏模式指针
	QGameMainMode* getMainMode();
	//得到当前游戏模式指针
	QGameMode* getCurrentMode();
};