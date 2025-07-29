#include "..\headers\Videogame.h"

Videogame::Videogame(string _title, string _description, unsigned int _year, string _publ, string _genre, string _dev) : DigitalItem(_title, _description, _year, _publ, _genre), developer(_dev){
};

string Videogame::getDeveloper() const{
    return this->developer;
};

void Videogame::setDeveloper(string d){
    this->developer=d;
};
