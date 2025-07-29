#ifndef BOOK_H
#define BOOK_H
#include "PhysicalItem.h"

class Book: public PhysicalItem{
private:
	string publisher;
	string genre;
	string edition;
public:
	Book(string _title, string _description, unsigned int _year, string _author, string _size, string _publisher, string _genre, string _edition);
	
	string getPublisher() const;
	void setPublisher(string);
	string getGenre() const;
	void setGenre(string);
	string getEdition() const;
    void setEdition(string);
};
#endif
