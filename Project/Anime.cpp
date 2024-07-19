#include "Anime.h"

Anime::Anime(const string& t, const string& g, const Date& rd) : title(t), genre(g), releaseDate(rd) {}

Anime::~Anime() {}

void Anime::print() const {
    cout << "Title: " << title << ", Genre: " << genre << ", Release Date: " << releaseDate.toString() << endl;
}

string Anime::getTitle() const {
    return title;
}

string Anime::getGenre() const {
    return genre;
}

Date Anime::getReleaseDate() const {
    return releaseDate;
}
