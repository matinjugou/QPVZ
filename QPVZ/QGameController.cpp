#include "QGameController.h"

QGameController::QGameController(QWidget* parent)
//	:QObject(parent)
{
	Loader = new QGameModeLoader;
	Displayer = new QGameDisplayer(Loader->getMainMode()->getScene());
	connect(Loader, SIGNAL(addItem(objectNames, QpointF)), Displayer, SLOT(addItem(objectNames, QPointF)));

}

QGameController::~QGameController()
{

}

void QGameController::exec()
{
	
}