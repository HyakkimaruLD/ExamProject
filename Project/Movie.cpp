#include "Movie.h"

Movie::Movie(const string& t, const string& g, const Date& rd, int d) : Anime(t, g, rd), duration(d) {}

void Movie::print() const {
    Anime::print();
    cout << "Duration: " << duration << " minutes" << endl;
}

int Movie::getDuration() const {
    return duration;
}
