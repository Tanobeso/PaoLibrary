#include "..\headers\Movie.h"

Movie::Movie(string _title, string _description, unsigned int _year, string _publisher, string _genre, string _cast, string _director, unsigned int _minutes) : Video(_title, _description, _year, _publisher, _genre, _cast, _director), minutes(_minutes){
};

unsigned int Movie::getLength() const{
    return minutes;
};

void Movie::setLength(unsigned int min=0){
    this->minutes=min;
};

QJsonObject Movie::toJson() const{
    QJsonObject obj;
    obj["type"]="movie";
    obj["title"]=QString::fromStdString(getTitle());
    obj["description"]=QString::fromStdString(getDescription());
    obj["year"]=(int)getYear();
    obj["publisher"]=QString::fromStdString(getPublisher());
    obj["genre"]=QString::fromStdString(getGenre());
    obj["cast"]=QString::fromStdString(getCast());
    obj["director"]=QString::fromStdString(getDirector());
    obj["length"]=(int)getLength();
    return obj;
};
