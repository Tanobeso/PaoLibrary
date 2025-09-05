#include "../headers/ItemInfoVisitor.h"
#include "../headers/Art.h"
#include "../headers/Book.h"
#include "../headers/Movie.h"
#include "../headers/Series.h"
#include "../headers/Videogame.h"
#include <QLineEdit>
#include <QValidator>

QWidget* ItemInfoVisitor::getWidget() {
    return infoWidget;
}

void ItemInfoVisitor::infoSetup(AbstractItem& item) {
    infoWidget = new QWidget();
    infoLayout = new QVBoxLayout(infoWidget);

    QLineEdit* titleEdit = new QLineEdit(QString::fromStdString(item.getTitle()));
    infoLayout->addWidget(titleEdit);
    infoLayout->addStretch();
    titleEdit->setReadOnly(true);

    QLabel* descriptionLabel = new QLabel("Description:");
    infoLayout->addWidget(descriptionLabel);
    infoLayout->addSpacing(8);
    QLineEdit* descriptionEdit = new QLineEdit(QString::fromStdString(item.getDescription()));
    infoLayout->addWidget(descriptionEdit);
    descriptionEdit->setReadOnly(true);
    infoLayout->addStretch();

    QLabel* yearLabel = new QLabel("Year:");
    infoLayout->addWidget(yearLabel);
    infoLayout->addSpacing(8);
    QLineEdit* yearEdit = new QLineEdit(QString::number(item.getYear()));
    infoLayout->addWidget(yearEdit);
    yearEdit->setReadOnly(true);
    yearEdit->setValidator(new QIntValidator(0, 2500));
}

void ItemInfoVisitor::visitArt(Art& art) {
    infoSetup(art);
}

void ItemInfoVisitor::visitBook(Book& book) {
    infoSetup(book);
}

void ItemInfoVisitor::visitMovie(Movie& movie) {
    infoSetup(movie);
}

void ItemInfoVisitor::visitSeries(Series& series) {
    infoSetup(series);
}

void ItemInfoVisitor::visitVideogame(Videogame& videogame) {
    infoSetup(videogame);
}

