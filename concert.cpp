#include "concert.h"

using namespace std;

//
// Created by Jeremiah Logan
//
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

Concert::Concert(string name, vector<string> friends, int desire, tm date) {
    this->concertName = name;
    this->friends = friends;
    this->desire = desire;
    time_t now = time(0);
    localtime(&now);
    this->setDate(date);
}

string Concert::getName()const {
    return concertName;
}

vector<string> Concert::getList() {
    return vector<string>();
}

int Concert::getDesire() const {
    return this->desire;
}

tm Concert::getDate() const {
    return this->date;
}

string Concert::setName(string name) {
    this->concertName = name;
}

int Concert::setDesire(int desire) {
    this->desire = desire;
}

vector<string> Concert::setFriends(vector<string> friends) {
    this->friends = friends;
}

tm Concert::setDate(tm date) {
    this->date = date;
}

bool Concert::operator<(const Concert &other) const {
    if (this->getDate().tm_year < other.getDate().tm_year) {
        return true;
    }

    if (this->getDate().tm_yday < other.getDate().tm_yday) {
        return true;
    }

    if (this->getDate().tm_hour < other.getDate().tm_hour) {
        return true;
    }

    /*if (this->getDate().tm_min < other.getDate().tm_min) {
        return true;
    }*/

    /*if (this->getDate().tm_sec < other.getDate().tm_sec) {
        return true;
    }else if (this->getDate().tm_sec == other.getDate().tm_sec) {
        if (this->getDesire() < other.getDesire()) {
            return true;
        }
    }*/
    return false;
}

ostream &operator<<(ostream &output, const Concert &C) {
    output << "Concert Name: " << C.getName()<< endl
           << "Date: " << 1 + C.getDate().tm_mon
           << "/"<<  C.getDate().tm_mday << "/"
           << 1900 + C.getDate().tm_year << endl
           << "Time: "<< 1 + C.getDate().tm_hour << ":"
           << 1 + C.getDate().tm_min << ":"
           << 1 + C.getDate().tm_sec << endl << "Desire Level: " << C.getDesire() << endl;
    return output;
}

