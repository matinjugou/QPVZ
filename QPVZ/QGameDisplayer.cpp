#include "QGameDisplayer.h"
#include "QPlants.h"
#include "QZombies.h"

QGameDisplayer::QGameDisplayer(QWidget *parent)
//	:QObject(parent)
{
	mainView = new QGraphicsView;
	mainView->setRenderHint(QPainter::Antialiasing);
	mainView->setCacheMode(QGraphicsView::CacheBackground);
	mainView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
	mainView->setDragMode(QGraphicsView::ScrollHandDrag);
	mainView->resize(900, 600);
	mainView->setFrameStyle(0);
	mainView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	mainView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

QGameDisplayer::QGameDisplayer(QGraphicsScene* scene, QWidget *parent)
//	:QObject(parent)
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

void QGameDisplayer::addItem(objectNames name, QPointF pos)
{
	switch (name)
	{
	case PeaShooter:
	{
		QPeaShooter* newPeashooter = new QPeaShooter(pos.x(), pos.y());
		currentScene->addItem(newPeashooter);
		emit Itemadded(newPeashooter);
	}
		break;
	default:
		break;
	}
}

QGraphicsScene* QGameDisplayer::getCurrentScene()
{
	return currentScene;
}

QGraphicsView* QGameDisplayer::getView()
{
	return mainView;
}
