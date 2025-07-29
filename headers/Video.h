#ifndef VIDEO_H
#define VIDEO_H
#include "DigitalItem.h"

class Video: public DigitalItem{
private:
	string cast;
	string director;
public:
	Video(string _title, string _description, unsigned int _year, string _publisher, string _genre, string _cast, string _director);

	string getCast() const;
	void setCast(string);
	string getDirector() const;
	void setDirector(string);
};

#endif
