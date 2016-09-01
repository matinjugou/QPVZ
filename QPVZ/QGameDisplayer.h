#pragma once
#include "qgraphicsview.h"
#include "qgraphicsscene.h"
#include "QMyObject.h"


class QGameDisplayer:public QObject
{
	Q_OBJECT
private:
	QGraphicsView *mainView;
	QGraphicsScene *currentScene;
public:
	QGameDisplayer(QWidget* parent = 0);
	QGameDisplayer(QGraphicsScene *scene, QWidget* parent = 0);
	~QGameDisplayer();
signals:
	void Itemadded(QMyObject*);
public slots:
	void setScene(QGraphicsScene* scene);
	void addItem(objectNames, QPointF);
public:
	QGraphicsView* getView();
	QGraphicsScene* getCurrentScene();
};