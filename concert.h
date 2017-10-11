//
// Created by Jeremiah Logan
//
#ifndef INCONCERT_CONCERT_H
#define INCONCERT_CONCERT_H

#include <string>
#include <vector>
#include <ctime>
#include <ostream>

using namespace std;
/*****************************************************************
 * Data holder for important information about Concerts held at
 * a venue
 *
 * @author Jeremiah Logan
 ****************************************************************/
class Concert {
public:
    //Constructor with no parameters
    Concert();
    //Constructor with parameters
    Concert(string name, vector<string> list, int desire, tm date);

    //Accessors
    string getName()const;
    int getDesire()const;
    tm getDate()const;

    //Setters
    tm setDate(tm date);

    //less than overload
    //Code found on Tutorialspoint.com
    bool operator<(const Concert &other) const;

private:
    // Who will be performing?
    string concertName;

    // A list of the people you want
    // to take with you.  May be empty
    // or arbitrarily full.
    vector<string> friends;

    // A value from 1-10 concerning how
    // badly you want to see this show.
    int desire;

    // The date of the show
    // See http://en.cppreference.com/w/cpp/chrono/c/tm
    tm date;
};

//<< overload
//Code found on Tutorialspoint.com
ostream &operator<<(ostream &output, const Concert &C);
#endif //INCONCERT_CONCERT_H
