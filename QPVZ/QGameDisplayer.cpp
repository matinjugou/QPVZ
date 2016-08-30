#include "QGameDisplayer.h"
#include "QPlants.h"
#include "QZombies.h"

QGameDisplayer::QGameDisplayer(QWidget *parent = 0)
	:QObject(parent)
{
	mainView = new QGraphicsView;
	mainView->setRenderHint(QPainter::Antialiasing);
	mainView->setCacheMode(QGraphicsView::CacheBackground);
	mainView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
	mainView->setDragMode(QGraphicsView::ScrollHandDrag);
	mainView->resize(900, 600);

}

QGameDisplayer::QGameDisplayer(QGraphicsScene* scene, QWidget *parent)
	:QObject(parent)
{
	mainView = new QGraphicsView;
	mainView->setRenderHint(QPainter::Antialiasing);
	mainView->setCacheMode(QGraphicsView::CacheBackground);
	mainView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
	mainView->setDragMode(QGraphicsView::ScrollHandDrag);
	mainView->resize(900, 600);

	mainView->setScene(scene);
}

QGameDisplayer::~QGameDisplayer()
{
	delete mainView;
}

void QGameDisplayer::setScene(QGraphicsScene *scene)
{
	currentScene = scene;
	mainView->setScene(currentScene);
}

void QGameDisplayer::addItem(objectNames name, Position pos)
{
	switch (name)
	{
	case PeaShooter:
		currentScene->addItem(new QPeaShooter(pos.x, pos.y));
		break; 
	default:
		break;
	}
}

