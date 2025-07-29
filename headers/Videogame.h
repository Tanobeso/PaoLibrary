#ifndef VIDEOGAME_H
#define VIDEOGAME_H
#include "DigitalItem.h"

class Videogame: public DigitalItem{
private:
	string developer;
public:
	Videogame(string _title, string _description, unsigned int _year, string _publ, string _genre, string dev);

	string getDeveloper() const;
	void setDeveloper(string);

};

#endif
