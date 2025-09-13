#ifndef NEWSERIESFORM_H
#define NEWSERIESFORM_H

#include "NewItemForm.h"

class NewSeriesForm : public NewItemForm{
    Q_OBJECT
private:
    QLineEdit *publisherEdit, *genreEdit, *castEdit, *directorEdit, *seasonsEdit, *episodesEdit;

public:
    NewSeriesForm(QWidget* parent = nullptr);
    std::shared_ptr<AbstractItem> createItem() const override;
};

#endif // NEWSERIESFORM_H
