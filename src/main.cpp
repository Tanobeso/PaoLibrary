#include "..\headers\mainwindow.h"

#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLabel hello("Hello My Nigga!\nMy little soda pop");
    hello.show();
    return a.exec();
}
