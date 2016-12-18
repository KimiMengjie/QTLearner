#include "T06Event.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    T06Event w;
    w.show();
    return a.exec();
}
