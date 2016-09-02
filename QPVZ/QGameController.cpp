#include "QGameController.h"

QGameController::QGameController(QWidget* parent)
//	:QObject(parent)
{
	Loader = new QGameModeLoader;
	Displayer = new QGameDisplayer(Loader->getMainMode()->getScene());
	Loader->setView(Displayer->getView());
	connect(Loader, SIGNAL(addItem(objectNames, QPointF)), Displayer, SLOT(addItem(objectNames, QPointF)));
	connect(Displayer, SIGNAL(Itemadded(QMyObject*)), Loader, SIGNAL(Itemadded(QMyObject*)));
	connect(Loader, SIGNAL(exchangetoScene(QGraphicsScene*)), Displayer, SLOT(setScene(QGraphicsScene*)));
}

QGameController::~QGameController()
{

}

void QGameController::exec()
{
	
}