#pragma once
#include <vector>
#include <algorithm>
#include <fstream>
#include <stdexcept>
#include "Anime.h"
#include "TVShow.h"
#include "Movie.h"

using namespace std;

class AnimeContainer {
private:
    vector<Anime*> animes;
public:
    ~AnimeContainer();
    void addAnime(Anime* anime);
    void removeAnime(const string& title);
    void editAnime(const string& title, Anime* newAnime);
    void printAll() const;
    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename);
    Anime* searchByTitle(const string& title) const;
    vector<Anime*> searchByGenre(const string& genre) const;
    void sortAnimes();
};
