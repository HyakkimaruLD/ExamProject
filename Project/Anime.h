#pragma once
#include <iostream>
#include <string>
#include "Date.h"

using namespace std;

class Anime {
protected:
    string title;
    string genre;
    Date releaseDate;
public:
    Anime(const string& t, const string& g, const Date& rd);
    virtual ~Anime();
    virtual void print() const;
    string getTitle() const;
    string getGenre() const;
    Date getReleaseDate() const;
};
