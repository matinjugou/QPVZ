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
	void exchangetoScene(QGraphicsScene*);
	//传递消息给Displayer切换到某个场景
	void addItem(objectNames, QPointF);
	//传递消息给Displayer添加物品
	void Itemadded(QMyObject*);
	//物品添加成功

public slots:
	void Load(int);
	//加载游戏模式
	void LoadAdventure();
	//加载冒险魔术，引入map之后可以优化掉
	void QuitMode();
	//退出当前模式
	void setView(QGraphicsView*);
	//设置视角，引入对象树系统后可以优化掉

public:
	QGameMainMode* getMainMode();
	//得到主要游戏模式指针
	QGameMode* getCurrentMode();
	//得到当前游戏模式指针
};