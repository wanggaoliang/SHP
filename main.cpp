#include "shp.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SHP w;
	w.show();
	return a.exec();
}
