#include "../headers/NewItemDialog.h"
#include "../headers/NewItemDialog.h"
#include <QDialogButtonBox>
#include <QVBoxLayout>
#include <QPushButton>

NewItemDialog::NewItemDialog(QWidget* parent) : QWidget(parent) {
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

    auto btnCreate = new QPushButton("Create");
    auto btnDiscard = new QPushButton("Discard");
    QHBoxLayout* buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(btnCreate);
    buttonLayout->addWidget(btnDiscard);
    connect(btnCreate, &QPushButton::clicked, this, [this]() {
        emit confirm();
    });
    connect(btnDiscard, &QPushButton::clicked, this, [this]() {
        emit discard();
    });


    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->addWidget(typeCombo);
    mainLayout->addWidget(stackedWidget);
    mainLayout->addLayout(buttonLayout);
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
