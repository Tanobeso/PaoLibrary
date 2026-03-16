#ifndef NEWITEMFORM_H
#define NEWITEMFORM_H
#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>
#include "AbstractItem.h"

class NewItemForm : public QWidget{
    Q_OBJECT
protected:
    QLineEdit *titleEdit, *yearEdit, *imageEdit;
    QTextEdit* descriptionEdit;
    QLabel* imagePreview;
public:
    explicit NewItemForm(QWidget* parent = nullptr) : QWidget(parent) {}
    virtual ~NewItemForm() = default;

    virtual std::shared_ptr<AbstractItem> createItem() const = 0;
protected slots:
    void onBrowse();
};

#endif // NEWITEMFORM_H
