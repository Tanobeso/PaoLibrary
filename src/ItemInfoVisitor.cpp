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
    QLabel* authorLabel = new QLabel("Author:");
    infoLayout->addWidget(authorLabel);
    QLineEdit* authorEdit = new QLineEdit(QString::fromStdString(art.getAuthor()));
    infoLayout->addWidget(authorEdit);
    authorEdit->setReadOnly(true);

    QLabel* sizeLabel = new QLabel("Size:");
    infoLayout->addWidget(sizeLabel);
    QLineEdit* sizeEdit = new QLineEdit(QString::fromStdString(art.getSize()));
    infoLayout->addWidget(sizeEdit);
    sizeEdit->setReadOnly(true);

    QLabel* styleLabel = new QLabel("Style:");
    infoLayout->addWidget(styleLabel);
    QLineEdit* styleEdit = new QLineEdit(QString::fromStdString(art.getStyle()));
    infoLayout->addWidget(styleEdit);
    styleEdit->setReadOnly(true);
}

void ItemInfoVisitor::visitBook(Book& book) {

    QLabel* authorLabel = new QLabel("Author:");
    infoLayout->addWidget(authorLabel);
    QLineEdit* authorEdit = new QLineEdit(QString::fromStdString(book.getAuthor()));
    infoLayout->addWidget(authorEdit);
    authorEdit->setReadOnly(true);

    QLabel* sizeLabel = new QLabel("Size:");
    infoLayout->addWidget(sizeLabel);
    QLineEdit* sizeEdit = new QLineEdit(QString::fromStdString(book.getSize()));
    infoLayout->addWidget(sizeEdit);
    sizeEdit->setReadOnly(true);

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

    QLabel* publisherLabel = new QLabel("Publisher:");
    infoLayout->addWidget(publisherLabel);
    QLineEdit* publisherEdit = new QLineEdit(QString::fromStdString(movie.getPublisher()));
    infoLayout->addWidget(publisherEdit);
    publisherEdit->setReadOnly(true);

    QLabel* directorLabel = new QLabel("Director:");
    infoLayout->addWidget(directorLabel);
    QLineEdit* directorEdit = new QLineEdit(QString::fromStdString(movie.getDirector()));
    infoLayout->addWidget(directorEdit);
    directorEdit->setReadOnly(true);

    QLabel* castLabel = new QLabel("Cast:");
    infoLayout->addWidget(castLabel);
    QLineEdit* castEdit = new QLineEdit(QString::fromStdString(movie.getCast()));
    infoLayout->addWidget(castEdit);
    castEdit->setReadOnly(true);

    QLabel* genreLabel = new QLabel("Genre:");
    infoLayout->addWidget(genreLabel);
    QLineEdit* genreEdit = new QLineEdit(QString::fromStdString(movie.getGenre()));
    infoLayout->addWidget(genreEdit);
    genreEdit->setReadOnly(true);

    QLabel* minutesLabel = new QLabel("Length:");
    infoLayout->addWidget(minutesLabel);
    QLineEdit* minutesEdit = new QLineEdit(QString::number(movie.getLength()));
    infoLayout->addWidget(minutesEdit);
    minutesEdit->setReadOnly(true);
    minutesEdit->setValidator(new QIntValidator(0, 600));
}

void ItemInfoVisitor::visitSeries(Series& series) {
    infoSetup(series);

    QLabel* publisherLabel = new QLabel("Publisher:");
    infoLayout->addWidget(publisherLabel);
    QLineEdit* publisherEdit = new QLineEdit(QString::fromStdString(series.getPublisher()));
    infoLayout->addWidget(publisherEdit);
    publisherEdit->setReadOnly(true);

    QLabel* directorLabel = new QLabel("Director:");
    infoLayout->addWidget(directorLabel);
    QLineEdit* directorEdit = new QLineEdit(QString::fromStdString(series.getDirector()));
    infoLayout->addWidget(directorEdit);
    directorEdit->setReadOnly(true);

    QLabel* castLabel = new QLabel("Cast:");
    infoLayout->addWidget(castLabel);
    QLineEdit* castEdit = new QLineEdit(QString::fromStdString(series.getCast()));
    infoLayout->addWidget(castEdit);
    castEdit->setReadOnly(true);

    QLabel* genreLabel = new QLabel("Genre:");
    infoLayout->addWidget(genreLabel);
    QLineEdit* genreEdit = new QLineEdit(QString::fromStdString(series.getGenre()));
    infoLayout->addWidget(genreEdit);
    genreEdit->setReadOnly(true);

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

    QLabel* publisherLabel = new QLabel("Publisher:");
    infoLayout->addWidget(publisherLabel);
    QLineEdit* publisherEdit = new QLineEdit(QString::fromStdString(videogame.getPublisher()));
    infoLayout->addWidget(publisherEdit);
    publisherEdit->setReadOnly(true);

    QLabel* genreLabel = new QLabel("Genre:");
    infoLayout->addWidget(genreLabel);
    QLineEdit* genreEdit = new QLineEdit(QString::fromStdString(videogame.getGenre()));
    infoLayout->addWidget(genreEdit);
    genreEdit->setReadOnly(true);

    QLabel* developerLabel = new QLabel("Developer:");
    infoLayout->addWidget(developerLabel);
    QLineEdit* developerEdit = new QLineEdit(QString::fromStdString(videogame.getDeveloper()));
    infoLayout->addWidget(developerEdit);
    developerEdit->setReadOnly(true);
}

void buttonSetup(AbstractItem&){
    //aggiungere shortcut per uscire dalla pagina
}
