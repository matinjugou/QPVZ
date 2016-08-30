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
public slots:
	void setScene(QGraphicsScene* scene);
	void addItem(objectNames, Position);
public:
	QGraphicsView* getView();
	QGraphicsScene* getCurrentScene();
};