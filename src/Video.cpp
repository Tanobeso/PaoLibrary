#include "../headers/Video.h"

Video::Video(string _title, string _description, unsigned int _year, string _publisher, string _genre, string _cast, string _director) : DigitalItem(_title, _description, _year, _publisher, _genre), cast(_cast), director(_director){
};

string Video::getCast() const{
    return this->cast;
};

void Video::setCast(string c){
    this->cast=c;
};

string Video::getDirector() const{
    return this->director;
};

void Video::setDirector(string d){
    this->director=d;
};
