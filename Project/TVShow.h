#pragma once
#include "Anime.h"

class TVShow : public Anime {
private:
    int seasons;
public:
    TVShow(const string& t, const string& g, const Date& rd, int s);
    void print() const override;
    int getSeasons() const; 
};
