#include "TVShow.h"

TVShow::TVShow(const string& t, const string& g, const Date& rd, int s) : Anime(t, g, rd), seasons(s) {}

void TVShow::print() const {
    Anime::print();
    cout << "Seasons: " << seasons << endl;
}

int TVShow::getSeasons() const {
    return seasons;
}
