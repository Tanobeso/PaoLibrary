#include "..\headers\Series.h"

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
    obj["type"]="movie";
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
