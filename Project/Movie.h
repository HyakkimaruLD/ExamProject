#pragma once
#include "Anime.h"

class Movie : public Anime {
private:
    int duration; 
public:
    Movie(const string& t, const string& g, const Date& rd, int d);
    void print() const override;
    int getDuration() const;
};