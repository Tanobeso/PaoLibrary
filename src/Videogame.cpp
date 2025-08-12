#include "..\headers\Videogame.h"

Videogame::Videogame(string _title, string _description, unsigned int _year, string _publ, string _genre, string _dev) : DigitalItem(_title, _description, _year, _publ, _genre), developer(_dev){
};

string Videogame::getDeveloper() const{
    return this->developer;
};

void Videogame::setDeveloper(string d){
    this->developer=d;
};

QJsonObject Videogame::toJson() const{
    QJsonObject obj;
    obj["type"]="movie";
    obj["title"]=QString::fromStdString(getTitle());
    obj["description"]=QString::fromStdString(getDescription());
    obj["year"]=(int)getYear();
    obj["publisher"]=QString::fromStdString(getPublisher());
    obj["genre"]=QString::fromStdString(getGenre());
    obj["developer"]=QString::fromStdString(getDeveloper());
    return obj;
};
