#include "..\headers\test_widget.h"
#include <QLayout>

Test_widget::Test_widget(std::string& stringa, QWidget* parent) : QWidget(parent), stringa(stringa) {
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->setAlignment ( Qt :: AlignLeft | Qt :: AlignTop ) ;
    label1 = new QLabel();
    layout->addWidget(label1);
    label2 = new QLabel();
    layout->addWidget(label2);
    layout->addStretch();
}

void Test_widget::show(){
    label1->setText( QString :: fromStdString(stringa));
    label2->setText( QString :: fromStdString(stringa));
};
