#include "QGameDisplayer.h"
#include "QPlants.h"
#include "QZombies.h"

QGameDisplayer::QGameDisplayer(QObject *parent)
	:QObject(parent)
{
	mainView = new QGraphicsView;
	mainView->setRenderHint(QPainter::Antialiasing);
	mainView->setCacheMode(QGraphicsView::CacheBackground);
	mainView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
	mainView->setDragMode(QGraphicsView::NoDrag);
	mainView->resize(900, 600);
	mainView->setFrameStyle(0);
	mainView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	mainView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

QGameDisplayer::QGameDisplayer(QGraphicsScene* scene, QObject *parent)
	:QObject(parent)
{
	mainView = new QGraphicsView;
	mainView->setRenderHint(QPainter::Antialiasing);
	mainView->setCacheMode(QGraphicsView::CacheBackground);
	mainView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
	mainView->setDragMode(QGraphicsView::NoDrag);
	mainView->resize(900, 600);
	mainView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	mainView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	mainView->setScene(scene);
}

QGameDisplayer::~QGameDisplayer()
{
	delete mainView;
}

//public slots
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
		QPeaShooter* newPeashooter = new QPeaShooter(pos.x(), pos.y(), this->currentScene);
		currentScene->addItem(newPeashooter);
		emit Itemadded(newPeashooter);
	}
	break;
	case CommonZombie:
	{
		QCommonZombie* newCommonZombie = new QCommonZombie(pos.x(), pos.y(), this->currentScene);
		currentScene->addItem(newCommonZombie);
		emit Itemadded(newCommonZombie);
	}
	break;
	case BucketHeadZombie:
	{
		QBucketHeadZombie* newBucketHeadZombie = new QBucketHeadZombie(pos.x(), pos.y(), this->currentScene);
		currentScene->addItem(newBucketHeadZombie);
		emit Itemadded(newBucketHeadZombie);
	}
	break;
	case PoleVaultingZombie:
	{
		QPoleVaultingZombie* newPoleVaultingZombie = new QPoleVaultingZombie(pos.x(), pos.y(), this->currentScene);
		currentScene->addItem(newPoleVaultingZombie);
		emit Itemadded(newPoleVaultingZombie);
	}
	break;
	case SunFlower:
	{
		QSunFlower* newSunFlower = new QSunFlower(pos.x(), pos.y(), this->currentScene);
		currentScene->addItem(newSunFlower);
		emit Itemadded(newSunFlower);
	}
	break;
	case WallNut:
	{
		QWallNut* newWallNut = new QWallNut(pos.x(), pos.y(), this->currentScene);
		currentScene->addItem(newWallNut);
		emit Itemadded(newWallNut);
	}
	break;
	default:
		break;
	}
}

//public
QGraphicsView* QGameDisplayer::getView()
{
	return mainView;
}

QGraphicsScene* QGameDisplayer::getCurrentScene()
{
	return currentScene;
}

