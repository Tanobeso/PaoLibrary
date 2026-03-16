#ifndef NEWVIDEOGAMEFORM_H
#define NEWVIDEOGAMEFORM_H
#include "NewItemForm.h"

class NewVideogameForm : public NewItemForm{
    Q_OBJECT
private:
    QLineEdit *publisherEdit, *genreEdit, *developerEdit;

public:
    NewVideogameForm(QWidget* parent = nullptr);
    std::shared_ptr<AbstractItem> createItem() const override;
};
#endif // NEWVIDEOGAMEFORM_H
