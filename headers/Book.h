#ifndef BOOK_H
#define BOOK_H
#include "PhysicalItem.h"

class Book: public PhysicalItem{
private:
	string publisher;
	string genre;
	string edition;
public:
    Book(string _title, string _description, unsigned int _year, string _image, string _author, string _size, string _publisher, string _genre, string _edition);
    Book()=default;

	string getPublisher() const;
    void setPublisher(const string&);
	string getGenre() const;
    void setGenre(const string&);
	string getEdition() const;
    void setEdition(const string&);

    QJsonObject toJson() const override;
    QDomElement toXml(QDomDocument &doc) const override;

    virtual void accept(ItemVisitor& visitor) override;
};
#endif
