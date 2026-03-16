#ifndef NEWARTFORM_H
#define NEWARTFORM_H
#include "NewItemForm.h"

class NewArtForm : public NewItemForm{
    Q_OBJECT
private:
    QLineEdit *authorEdit, *sizeEdit, *styleEdit;

public:
    NewArtForm(QWidget* parent = nullptr);
    std::shared_ptr<AbstractItem> createItem() const override;
};
#endif // NEWARTFORM_H
