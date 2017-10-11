#include "concert.h"

#include <utility>

using namespace std;

/*****************************************************************
 * Default constructor instantiates Concert Data
 ****************************************************************/
Concert::Concert() : desire(desire) {
    this->concertName = "Eminem & Rihanna";
    this->friends.insert(friends.begin(), "Jeremiah");
    srand(rand());
    this->desire = rand() % 10;
    this->date.tm_year = 100 + rand() % 17;
    this->date.tm_mon = (rand() % 11) + 1;
    this->date.tm_mday = (rand() % 29) + 1;
    this->date.tm_hour = rand() % 24;
    this->date.tm_min = rand() % 60;
    this->date.tm_sec = rand() % 60;

}

/*****************************************************************
 * Constructor creates Concert with information provided
 *
 * @param name - Name of the Concert
 * @param friends - List of friends name who are attending
 * @param date - Concert date and time
 * @param desire - Concert Popularity on scale 0-9
 ****************************************************************/
Concert::Concert(string name, vector<string> friends, int desire, tm date) {
    this->concertName = std::move(name);
    this->friends = std::move(friends);
    this->desire = desire;
    time_t now = time(nullptr);
    localtime(&now);
    this->setDate(date);
}

/*****************************************************************
 * Returns Concert's Name
 ****************************************************************/
string Concert::getName() const {
    return concertName;
}

/*****************************************************************
 * Returns Concert's Desire Level
 ****************************************************************/
int Concert::getDesire() const {
    return this->desire;
}

/*****************************************************************
 * Returns Concert's Date/Time
 ****************************************************************/
tm Concert::getDate() const {
    return this->date;
}

/*****************************************************************
 * Changes the Concerts Date/Time
 * @param date - new Date/Time
 ****************************************************************/
tm Concert::setDate(tm date) {
    this->date = date;
}

/*****************************************************************
 * Overloading the < operator to allow sorting of concerts
 ****************************************************************/
bool Concert::operator<(const Concert &other) const {
    tm A = this->getDate();
    tm B = other.getDate();
    double time = difftime(mktime(&A), mktime(&B));
    if (time < 0) {
        return true;
    } else if (time == 0) {
        if (this->getDesire() < other.getDesire()) {
            return true;
        }
    } else {
        return false;
    }
}

/*****************************************************************
 * Overloading << operator for custom formatted output
 ****************************************************************/
ostream &operator<<(ostream &output, const Concert &C) {
    output << "Concert Name: " << C.getName() << endl
           << "Date: " << 1 + C.getDate().tm_mon
           << "/" << C.getDate().tm_mday << "/"
           << 1900 + C.getDate().tm_year << endl
           << "Time: " << 1 + C.getDate().tm_hour << ":"
           << 1 + C.getDate().tm_min << ":"
           << 1 + C.getDate().tm_sec << endl << "Desire Level: " << C.getDesire() << endl;
    return output;
}

