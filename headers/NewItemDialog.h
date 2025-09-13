#ifndef NEWITEMDIALOG_H
#define NEWITEMDIALOG_H
#include <QDialog>
#include <QComboBox>
#include <QStackedWidget>
#include "NewArtForm.h"
#include "NewBookForm.h"
#include "NewMovieForm.h"
#include "NewSeriesForm.h"
#include "NewVideogameForm.h"

class NewItemDialog : public QDialog {
    Q_OBJECT
public:
    explicit NewItemDialog(QWidget* parent = nullptr);

    std::shared_ptr<AbstractItem> createItem() const;

private slots:
    void onTypeChanged(int index);

private:
    QComboBox* typeCombo;
    QStackedWidget* stackedWidget;
    NewArtForm* artForm;
    NewBookForm* bookForm;
    NewMovieForm* movieForm;
    NewSeriesForm* seriesForm;
    NewVideogameForm* videogameForm;
};

#endif // NEWITEMDIALOG_H
