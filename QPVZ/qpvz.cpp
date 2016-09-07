#include "qpvz.h"
#include <ctime>

QPVZ::QPVZ(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	Controller = new QGameController;
	setCentralWidget(Controller->Displayer->getView());
	srand(unsigned(time(0)));
	setFixedSize(900, 600);
	//Controller->Displayer->getView()->show();
}

QPVZ::~QPVZ()
{

}
