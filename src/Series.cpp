#include "../headers/Series.h"

Series::Series(string _title, string _description, unsigned int _year, string _publisher, string _genre, string _cast, string _director, unsigned int _seasons, unsigned int _episodes) : Video(_title, _description, _year, _publisher, _genre, _cast, _director), seasons(_seasons), episodes(_episodes){
};

unsigned int Series::getSeasons() const{
    return this->seasons;
};

void Series::setSeasons(unsigned int s){
    this->seasons=s;
};

unsigned int Series::getEpisodes() const{
    return this->episodes;
};

void Series::setEpisodes(unsigned int e){
    this->episodes=e;
};

QJsonObject Series::toJson() const{
    QJsonObject obj;
    obj["type"]="series";
    obj["title"]=QString::fromStdString(getTitle());
    obj["description"]=QString::fromStdString(getDescription());
    obj["year"]=(int)getYear();
    obj["publisher"]=QString::fromStdString(getPublisher());
    obj["genre"]=QString::fromStdString(getGenre());
    obj["cast"]=QString::fromStdString(getCast());
    obj["director"]=QString::fromStdString(getDirector());
    obj["seasons"]=(int)getSeasons();
    obj["episodes"]=(int)getEpisodes();
    return obj;
};

QDomElement Series::toXml(QDomDocument &doc) const {
    QDomElement e = doc.createElement("Series");
    e.appendChild(doc.createElement("Title")).appendChild(doc.createTextNode(QString::fromStdString(getTitle())));
    e.appendChild(doc.createElement("Description")).appendChild(doc.createTextNode(QString::fromStdString(getDescription())));
    e.appendChild(doc.createElement("Year")).appendChild(doc.createTextNode(QString::number (getYear())));
    e.appendChild(doc.createElement("Publisher")).appendChild(doc.createTextNode(QString::fromStdString(getPublisher())));
    e.appendChild(doc.createElement("Genre")).appendChild(doc.createTextNode(QString::fromStdString(getGenre())));
    e.appendChild(doc.createElement("Cast")).appendChild(doc.createTextNode(QString::fromStdString(getCast())));
    e.appendChild(doc.createElement("Director")).appendChild(doc.createTextNode(QString::fromStdString(getDirector())));
    e.appendChild(doc.createElement("Seasons")).appendChild(doc.createTextNode(QString::number (getSeasons())));
    e.appendChild(doc.createElement("Episodes")).appendChild(doc.createTextNode(QString::number (getEpisodes())));
    return e;
}
