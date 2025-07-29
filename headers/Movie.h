#ifndef MOVIE_H
#define MOVIE_H
#include "Video.h"

class Movie: public Video{
private:
	unsigned int minutes;
public:
	Movie(string _title, string _description, unsigned int _year, string _publisher, string _genre, string _cast, string _director, unsigned int _minutes);

    unsigned int getLength() const;
    void setLength(unsigned int);
};

#endif
