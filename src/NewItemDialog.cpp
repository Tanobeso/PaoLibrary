#include "../headers/NewItemDialog.h"
#include "../headers/NewItemDialog.h"
#include <QDialogButtonBox>
#include <QVBoxLayout>
#include <QPushButton>

NewItemDialog::NewItemDialog(QWidget* parent) : QDialog(parent) {
    setWindowTitle("New item");

    typeCombo = new QComboBox();
    typeCombo->addItems({"Art", "Book", "Movie", "Series", "Videogame"});
    connect(typeCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &NewItemDialog::onTypeChanged);

    stackedWidget = new QStackedWidget();

    artForm = new NewArtForm();
    bookForm = new NewBookForm();
    movieForm = new NewMovieForm();
    seriesForm = new NewSeriesForm();
    videogameForm = new NewVideogameForm();

    stackedWidget->addWidget(artForm);
    stackedWidget->addWidget(bookForm);
    stackedWidget->addWidget(movieForm);
    stackedWidget->addWidget(seriesForm);
    stackedWidget->addWidget(videogameForm);

    QDialogButtonBox* buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    buttonBox->button(QDialogButtonBox::Ok)->setText("Create");
    buttonBox->button(QDialogButtonBox::Cancel)->setText("Discard");
    connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->addWidget(typeCombo);
    mainLayout->addWidget(stackedWidget);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);

    stackedWidget->setCurrentIndex(0);
}

void NewItemDialog::onTypeChanged(int index) {
    stackedWidget->setCurrentIndex(index);
}

std::shared_ptr<AbstractItem> NewItemDialog::createItem() const {
    NewItemForm* current = qobject_cast<NewItemForm*>(stackedWidget->currentWidget());
    if (current)
        return current->createItem();
    return nullptr;
}
