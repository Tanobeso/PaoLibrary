#include "..\headers\mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    std::string stringa("Pippo");
    MainWindow mainwindow;
    mainwindow.resize(1024,512);
    mainwindow.show();
    return a.exec();
}
