#include "concert.h"

using namespace std;
//
// Created by Jeremiah Logan
//
Concert::Concert() : desire(desire) {
    this->concertName = "Eminem & Rihanna";
    this->friends.insert(friends.begin(),"Jeremiah");
    srand(rand());
    this->desire = rand() % 10;
    this->date.tm_year = rand() % 200;
    this->date.tm_mon = (rand() % 11)+1;
    this->date.tm_mday = (rand() % 29) + 1;
    this->date.tm_hour = rand() % 24 ;
    this->date.tm_min = rand() % 60 ;
    this->date.tm_sec = rand() % 60 ;

}

Concert::Concert(string name,vector<string> friends, int desire,tm date) {
    this->concertName = name;
    this->friends = friends;
    this->desire = desire;
    this->date = date;
}

string Concert::getName() {
    return concertName;
}

vector<string> Concert::getList() {
    return vector<string>();
}

int Concert::getDesire() {
    return this->desire;
}

tm Concert::getDate() {
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
    if(this->date.tm_year < other.date.tm_year){
        return true;
    }else if(this->date.tm_mon < other.date.tm_mon){
        return true;
    }else if(this->date.tm_mday < other.date.tm_mday){
        return true;
    }else if(this->date.tm_hour < other.date.tm_hour){
        return true;
    }else if(this->date.tm_min < other.date.tm_min){
        return true;
    }else if(this->date.tm_sec < other.date.tm_sec){
        return true;
    }else if(this->date.tm_sec == other.date.tm_sec){
        if(this->desire > other.desire){
            return true;
        }
    }
    return false;
}
