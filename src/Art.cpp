#include "..\headers\Art.h"

Art::Art(string _title, string _description, unsigned int _year, string _author, string _size, string _style) : PhysicalItem(_title, _description, _year, _author, _size), style(_style){
};

string Art::getStyle() const{
    return this->style;
};

void Art::setStyle(string s){
    this->style=s;
};
