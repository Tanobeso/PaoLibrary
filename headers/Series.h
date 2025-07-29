#ifndef SERIES_H
#define SERIES_H
#include "Video.h"

class Series: public Video{
private:
	unsigned int seasons;
	unsigned int episodes;
public:
	Series(string _title, string _description, unsigned int _year, string _publisher, string _genre, string _cast, string _director, unsigned int _seasons, unsigned int _episodes);

	unsigned int getSeasons() const;
	void setSeasons(unsigned int);
	unsigned int getEpisodes() const;
	void setEpisodes(unsigned int);
};

#endif
