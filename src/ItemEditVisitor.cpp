#include "../headers/ItemEditVisitor.h"
#include "../headers/Art.h"
#include "../headers/Book.h"
#include "../headers/Movie.h"
#include "../headers/Series.h"
#include "../headers/Videogame.h"

ItemEditVisitor::ItemEditVisitor(QList<QString>& _modifiche) : modifiche(_modifiche) {};

void ItemEditVisitor::visitArt(Art& art){
    art.setTitle(modifiche[0].toStdString());
    art.setDescription(modifiche[1].toStdString());
    art.setYear(modifiche[2].toUInt());
    art.setAuthor(modifiche[3].toStdString());
    art.setSize(modifiche[4].toStdString());
    art.setStyle(modifiche[5].toStdString());
};
void ItemEditVisitor::visitBook(Book& book){
    book.setTitle(modifiche[0].toStdString());
    book.setDescription(modifiche[1].toStdString());
    book.setYear(modifiche[2].toUInt());
    book.setAuthor(modifiche[3].toStdString());
    book.setSize(modifiche[4].toStdString());
    book.setPublisher(modifiche[5].toStdString());
    book.setGenre(modifiche[6].toStdString());
    book.setEdition(modifiche[7].toStdString());
};
void ItemEditVisitor::visitMovie(Movie& movie){
    movie.setTitle(modifiche[0].toStdString());
    movie.setDescription(modifiche[1].toStdString());
    movie.setYear(modifiche[2].toUInt());
    movie.setPublisher(modifiche[3].toStdString());
    movie.setDirector(modifiche[4].toStdString());
    movie.setCast(modifiche[5].toStdString());
    movie.setGenre(modifiche[6].toStdString());
    movie.setLength(modifiche[7].toUInt());
};
void ItemEditVisitor::visitSeries(Series& series){
    series.setTitle(modifiche[0].toStdString());
    series.setDescription(modifiche[1].toStdString());
    series.setYear(modifiche[2].toUInt());
    series.setPublisher(modifiche[3].toStdString());
    series.setDirector(modifiche[4].toStdString());
    series.setCast(modifiche[5].toStdString());
    series.setGenre(modifiche[6].toStdString());
    series.setSeasons(modifiche[7].toUInt());
    series.setEpisodes(modifiche[8].toUInt());
};
void ItemEditVisitor::visitVideogame(Videogame& videogame){
    videogame.setTitle(modifiche[0].toStdString());
    videogame.setDescription(modifiche[1].toStdString());
    videogame.setYear(modifiche[2].toUInt());
    videogame.setPublisher(modifiche[3].toStdString());
    videogame.setGenre(modifiche[4].toStdString());
    videogame.setDeveloper(modifiche[5].toStdString());
};
