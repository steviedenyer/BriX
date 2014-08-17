#include "BxMainWindow.h"

#include <QApplication>

int main(int argc, char** argv)
{
    QApplication a(argc, argv);
    BxMainWindow w;
    w.setGeometry(100, 100, 800, 500);
    w.show();

    return a.exec();


}
