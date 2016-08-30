//Make a difference
#include "qpvz.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QPVZ w;
	w.show();
	return a.exec();
}
