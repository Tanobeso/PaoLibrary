#ifndef JSONMANAGER_H
#define JSONMANAGER_H

#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>
#include <QList>
#include <memory>
#include "Art.h"
#include "Book.h"
#include "Movie.h"
#include "Series.h"
#include "Videogame.h"

QList<std::shared_ptr<AbstractItem>> loadJson(const QString &filePath);
std::shared_ptr<Art> fromJsonArt(QJsonObject&);
std::shared_ptr<Book> fromJsonBook(QJsonObject&);
std::shared_ptr<Movie> fromJsonMovie(QJsonObject&);
std::shared_ptr<Series> fromJsonSeries(QJsonObject&);
std::shared_ptr<Videogame> fromJsonVideogame(QJsonObject&);

#endif // JSONMANAGER_H
