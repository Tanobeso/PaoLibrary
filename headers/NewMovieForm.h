#ifndef NEWMOVIEFORM_H
#define NEWMOVIEFORM_H
#include "NewItemForm.h"

class NewMovieForm : public NewItemForm{
    Q_OBJECT
private:
    QLineEdit *publisherEdit, *genreEdit, *castEdit, *directorEdit, *lengthEdit;

public:
    NewMovieForm(QWidget* parent = nullptr);
    std::shared_ptr<AbstractItem> createItem() const override;
};
#endif // NEWMOVIEFORM_H
