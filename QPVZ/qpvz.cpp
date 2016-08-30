#include "qpvz.h"
#include "QGameController.h"

QPVZ::QPVZ(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	QGameController *Controller = new QGameController(this);
	
}

QPVZ::~QPVZ()
{

}
