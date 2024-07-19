#include "AnimeContainer.h"

AnimeContainer::~AnimeContainer() {
    for (Anime* anime : animes) 
    {
        delete anime;
    }
}

void AnimeContainer::addAnime(Anime* anime) {
    animes.push_back(anime);
}

void AnimeContainer::removeAnime(const string& title) {
    auto it = remove_if(animes.begin(), animes.end(), [&](Anime* anime) { return anime->getTitle() == title; });
    if (it != animes.end()) 
    {
        delete* it;
        animes.erase(it);
    }
}

void AnimeContainer::editAnime(const string& title, Anime* newAnime) {
    for (Anime*& anime : animes) 
    {
        if (anime->getTitle() == title) 
        {
            delete anime;
            anime = newAnime;
            return;
        }
    }
}

void AnimeContainer::printAll() const {
    for (const Anime* anime : animes) 
    {
        anime->print();
    }
}

void AnimeContainer::saveToFile(const string& filename) const {
    ofstream ofs(filename);
    if (!ofs) throw runtime_error("Unable to open file for writing");

    for (const Anime* anime : animes) 
    {
        const TVShow* tv = dynamic_cast<const TVShow*>(anime);
        if (tv) 
        {
            ofs << "TVShow " << tv->getTitle() << " " << tv->getGenre() << " " << tv->getReleaseDate().toString() << " " << tv->getSeasons() << endl;
            continue;
        }
        const Movie* mv = dynamic_cast<const Movie*>(anime);
        if (mv) 
        {
            ofs << "Movie " << mv->getTitle() << " " << mv->getGenre() << " " << mv->getReleaseDate().toString() << " " << mv->getDuration() << endl; 
        }
    }
}

void AnimeContainer::loadFromFile(const string& filename) {
    ifstream ifs(filename);
    if (!ifs) throw runtime_error("Unable to open file for reading");

    string type, title, genre, dateStr;
    int param;

    while (ifs >> type >> title >> genre >> dateStr >> param) 
    {
        int day, month, year;
#ifdef _MSC_VER
        sscanf_s(dateStr.c_str(), "%d/%d/%d", &day, &month, &year); 
#else
        sscanf(dateStr.c_str(), "%d/%d/%d", &day, &month, &year); 
#endif
        Date date(day, month, year);

        if (type == "TVShow") 
        {
            addAnime(new TVShow(title, genre, date, param));
        }
        else if (type == "Movie") 
        {
            addAnime(new Movie(title, genre, date, param));
        }
    }
}

Anime* AnimeContainer::searchByTitle(const string& title) const {
    for (const Anime* anime : animes) 
    {
        if (anime->getTitle() == title) 
        {
            return const_cast<Anime*>(anime);
        }
    }
    return nullptr;
}

vector<Anime*> AnimeContainer::searchByGenre(const string& genre) const {
    vector<Anime*> result;
    for (const Anime* anime : animes) 
    {
        if (anime->getGenre() == genre) 
        {
            result.push_back(const_cast<Anime*>(anime));
        }
    }
    return result;
}

void AnimeContainer::sortAnimes() {
    sort(animes.begin(), animes.end(), [](Anime* a, Anime* b) { return a->getReleaseDate() < b->getReleaseDate(); });
}
