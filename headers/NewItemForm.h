#ifndef NEWITEMFORM_H
#define NEWITEMFORM_H
#include <QWidget>
#include "AbstractItem.h"

class NewItemForm : public QWidget{
    Q_OBJECT
public:
    explicit NewItemForm(QWidget* parent = nullptr) : QWidget(parent) {}
    virtual ~NewItemForm() = default;

    virtual std::shared_ptr<AbstractItem> createItem() const = 0;
};

#endif // NEWITEMFORM_H
