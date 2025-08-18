#ifndef XMLMANAGER_H
#define XMLMANAGER_H

#include <QFile>
#include <QDomDocument>
#include <QDebug>
#include <QList>
#include <memory>
#include "Art.h"
#include "Book.h"
#include "Movie.h"
#include "Series.h"
#include "Videogame.h"

QList<std::shared_ptr<AbstractItem>> loadXml(const QString &filePath);
std::shared_ptr<Art> fromXmlArt(const QDomElement &element);
std::shared_ptr<Book> fromXmlBook(const QDomElement &element);
std::shared_ptr<Movie> fromXmlMovie(const QDomElement &element);
std::shared_ptr<Series> fromXmlSeries(const QDomElement &element);
std::shared_ptr<Videogame> fromXmlVideogame(const QDomElement &element);

#endif // XMLMANAGER_H
