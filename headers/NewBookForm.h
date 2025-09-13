#ifndef NEWBOOKFORM_H
#define NEWBOOKFORM_H
#include "NewItemForm.h"

class NewBookForm : public NewItemForm{
    Q_OBJECT
private:
    QLineEdit *authorEdit, *sizeEdit, *publisherEdit, *genreEdit, *editionEdit;

public:
    NewBookForm(QWidget* parent = nullptr);
    std::shared_ptr<AbstractItem> createItem() const override;
};

#endif // NEWBOOKFORM_H
