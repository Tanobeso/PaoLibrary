#ifndef ITEMVISITOR_H
#define ITEMVISITOR_H


class AbstractItem;
class Art;
class Book;
class Movie;
class Series;
class Videogame;

class ItemVisitor{
public:
    virtual ~ItemVisitor()=default;
    virtual void visitArt(Art& art)=0;
    virtual void visitBook(Book& book)=0;
    virtual void visitMovie(Movie& movie)=0;
    virtual void visitSeries(Series& series)=0;
    virtual void visitVideogame(Videogame& videogame)=0;
};

#endif // ITEMVISITOR_H
