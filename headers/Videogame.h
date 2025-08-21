#ifndef VIDEOGAME_H
#define VIDEOGAME_H
#include "DigitalItem.h"

class Videogame: public DigitalItem{
private:
	string developer;
public:
    Videogame(string _title, string _description, unsigned int _year, string _image, string _publ, string _genre, string dev);
    Videogame()=default;

	string getDeveloper() const;
    void setDeveloper(const string&);

    QJsonObject toJson() const override;
    QDomElement toXml(QDomDocument &doc) const override;
};

#endif
