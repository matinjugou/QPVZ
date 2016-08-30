#include "QGameController.h"

QGameController::QGameController(QWidget* parent)
//	:QObject(parent)
{
	Loader = new QGameModeLoader;
	Displayer = new QGameDisplayer(Loader->getMainMode()->getScene());
	connect(Loader, SIGNAL(addItem(objectNames, Position)), Displayer, SLOT(addItem(objectNames, Position)));

}

QGameController::~QGameController()
{

}

void QGameController::exec()
{
	
}