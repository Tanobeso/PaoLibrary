#ifndef NEWARTFORM_H
#define NEWARTFORM_H
#include "NewItemForm.h"
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>


class NewArtForm : public NewItemForm{
    Q_OBJECT
private:
    QLineEdit *titleEdit, *yearEdit, *authorEdit, *sizeEdit, *styleEdit, *imageEdit;
    QTextEdit* descriptionEdit;
    QLabel* imagePreview;
public:
    NewArtForm(QWidget* parent = nullptr);
    std::shared_ptr<AbstractItem> createItem() const override;
private slots:
    void onBrowse();
};
#endif // NEWARTFORM_H
