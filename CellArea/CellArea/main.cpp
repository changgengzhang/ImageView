#include "CellArea.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	CellArea w;
	w.show();
	return a.exec();
}
