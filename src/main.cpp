#include "..\headers\mainwindow.h"

#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    std::string stringa("Pippo");
    MainWindow mainwindow(stringa);
    mainwindow.resize(1024,512);
    mainwindow.show();
    return a.exec();
}
