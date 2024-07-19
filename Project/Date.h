#pragma once
#include <string>
#include <sstream>

using namespace std;

class Date {
private:
    int day, month, year;
public:
    Date();
    Date(int d, int m, int y);
    string toString() const;
    bool operator<(const Date& other) const;
    bool operator==(const Date& other) const;
};
