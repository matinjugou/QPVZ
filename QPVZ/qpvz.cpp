#include "qpvz.h"

QPVZ::QPVZ(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	Controller = new QGameController;
	setCentralWidget(Controller->Displayer->getView());
	setFixedSize(905, 605);
	//Controller->Displayer->getView()->show();
}

QPVZ::~QPVZ()
{

}
