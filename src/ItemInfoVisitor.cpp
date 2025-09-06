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
    titleEdit->setReadOnly(true);

    QLabel* descriptionLabel = new QLabel("Description:");
    infoLayout->addWidget(descriptionLabel);
    QLineEdit* descriptionEdit = new QLineEdit(QString::fromStdString(item.getDescription()));
    infoLayout->addWidget(descriptionEdit);
    descriptionEdit->setReadOnly(true);

    QLabel* yearLabel = new QLabel("Year:");
    infoLayout->addWidget(yearLabel);
    QLineEdit* yearEdit = new QLineEdit(QString::number(item.getYear()));
    infoLayout->addWidget(yearEdit);
    yearEdit->setReadOnly(true);
    yearEdit->setValidator(new QIntValidator(0, 2500));
}

void ItemInfoVisitor::visitArt(Art& art) {
    infoSetup(art);
    QLabel* styleLabel = new QLabel("Style:");
    infoLayout->addWidget(styleLabel);
    QLineEdit* styleEdit = new QLineEdit(QString::fromStdString(art.getStyle()));
    infoLayout->addWidget(styleEdit);
    styleEdit->setReadOnly(true);
}

void ItemInfoVisitor::visitBook(Book& book) {
    infoSetup(book);
    QLabel* publisherLabel = new QLabel("Publisher:");
    infoLayout->addWidget(publisherLabel);
    QLineEdit* publisherEdit = new QLineEdit(QString::fromStdString(book.getPublisher()));
    infoLayout->addWidget(publisherEdit);
    publisherEdit->setReadOnly(true);;

    QLabel* genreLabel = new QLabel("Genre:");
    infoLayout->addWidget(genreLabel);
    QLineEdit* genreEdit = new QLineEdit(QString::fromStdString(book.getGenre()));
    infoLayout->addWidget(genreEdit);
    genreEdit->setReadOnly(true);

    QLabel* editionLabel = new QLabel("Edition:");
    infoLayout->addWidget(editionLabel);
    QLineEdit* editionEdit = new QLineEdit(QString::fromStdString(book.getEdition()));
    infoLayout->addWidget(editionEdit);
    editionEdit->setReadOnly(true);
}

void ItemInfoVisitor::visitMovie(Movie& movie) {
    infoSetup(movie);
    QLabel* minutesLabel = new QLabel("Length:");
    infoLayout->addWidget(minutesLabel);
    QLineEdit* minutesEdit = new QLineEdit(QString::number(movie.getLength()));
    infoLayout->addWidget(minutesEdit);
    minutesEdit->setReadOnly(true);
    minutesEdit->setValidator(new QIntValidator(0, 600));
}

void ItemInfoVisitor::visitSeries(Series& series) {
    infoSetup(series);
    QLabel* seasonsLabel = new QLabel("Seasons:");
    infoLayout->addWidget(seasonsLabel);
    QLineEdit* seasonsEdit = new QLineEdit(QString::number(series.getSeasons()));
    infoLayout->addWidget(seasonsEdit);
    seasonsEdit->setReadOnly(true);
    seasonsEdit->setValidator(new QIntValidator(0, 100));

    QLabel* episodesLabel = new QLabel("Episodes:");
    infoLayout->addWidget(episodesLabel);
    QLineEdit* episodesEdit = new QLineEdit(QString::number(series.getEpisodes()));
    infoLayout->addWidget(episodesEdit);
    episodesEdit->setReadOnly(true);
    episodesEdit->setValidator(new QIntValidator(0, 10000));

}

void ItemInfoVisitor::visitVideogame(Videogame& videogame) {
    infoSetup(videogame);
    QLabel* developerLabel = new QLabel("Developer:");
    infoLayout->addWidget(developerLabel);
    QLineEdit* developerEdit = new QLineEdit(QString::fromStdString(videogame.getDeveloper()));
    infoLayout->addWidget(developerEdit);
    developerEdit->setReadOnly(true);
}

void buttonSetup(AbstractItem&){
    //aggiungere shortcut per uscire dalla pagina
}
