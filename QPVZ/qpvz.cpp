#include "qpvz.h"

QPVZ::QPVZ(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	Controller = new QGameController;
	setCentralWidget(Controller->Displayer->getView());
	setFixedSize(900, 600);
	//Controller->Displayer->getView()->show();
}

QPVZ::~QPVZ()
{

}
