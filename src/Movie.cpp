#include "../headers/Movie.h"

Movie::Movie(string _title, string _description, unsigned int _year, string _image, string _publisher, string _genre, string _cast, string _director, unsigned int _minutes) : Video(_title, _description, _year, _image, _publisher, _genre, _cast, _director), minutes(_minutes){
};

unsigned int Movie::getLength() const{
    return minutes;
};

void Movie::setLength(const unsigned int& min){
    this->minutes=min;
};

QJsonObject Movie::toJson() const{
    QJsonObject obj;
    obj["type"]="movie";
    obj["title"]=QString::fromStdString(getTitle());
    obj["description"]=QString::fromStdString(getDescription());
    obj["year"]=(int)getYear();
    obj["image"]=QString::fromStdString(getImage());
    obj["publisher"]=QString::fromStdString(getPublisher());
    obj["genre"]=QString::fromStdString(getGenre());
    obj["cast"]=QString::fromStdString(getCast());
    obj["director"]=QString::fromStdString(getDirector());
    obj["length"]=(int)getLength();
    return obj;
};

QDomElement Movie::toXml(QDomDocument &doc) const {
    QDomElement e = doc.createElement("Movie");
    e.appendChild(doc.createElement("Title")).appendChild(doc.createTextNode(QString::fromStdString(getTitle())));
    e.appendChild(doc.createElement("Description")).appendChild(doc.createTextNode(QString::fromStdString(getDescription())));
    e.appendChild(doc.createElement("Year")).appendChild(doc.createTextNode(QString::number (getYear())));
    e.appendChild(doc.createElement("Image")).appendChild(doc.createTextNode(QString::fromStdString(getImage())));
    e.appendChild(doc.createElement("Publisher")).appendChild(doc.createTextNode(QString::fromStdString(getPublisher())));
    e.appendChild(doc.createElement("Genre")).appendChild(doc.createTextNode(QString::fromStdString(getGenre())));
    e.appendChild(doc.createElement("Cast")).appendChild(doc.createTextNode(QString::fromStdString(getCast())));
    e.appendChild(doc.createElement("Director")).appendChild(doc.createTextNode(QString::fromStdString(getDirector())));
    e.appendChild(doc.createElement("Length")).appendChild(doc.createTextNode(QString::number (getLength())));
    return e;
}
