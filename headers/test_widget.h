#ifndef TEST_WIDGET_H
#define TEST_WIDGET_H
#include <QWidget>
#include <QLabel>
#include <string>

class Test_widget: public QWidget{
    Q_OBJECT
private:
    std::string stringa;
    QLabel* label1;
    QLabel* label2;
public:
    Test_widget(std::string& stringa, QWidget* parent = 0);
    void show();
};

#endif // TEST_WIDGET_H
