#include <iostream>
#include <vector>
#include <algorithm>
#include "concert.h"

using namespace std;

int main(int argc, char **argv) {

    vector<Concert>Schedule;
    time_t now = time(0);
    tm *ltm = localtime(&now);
    Concert A = Concert();
    Concert B = Concert("Wiz Khalifa and Li'l Wayne",{"Morgan Freeman","Beyonce"},3,*ltm);
    tm time = *ltm;
    time.tm_hour = 7;
    Concert C = Concert("Kanye",{"Morgan Freeman","Beyonce"},5,time);
    Schedule.insert(Schedule.begin(),A);
    Schedule.insert(Schedule.end(),B);
    Schedule.insert(Schedule.end(),C);
    for(int i = 0; i < 10;i++) {
        Concert temp = Concert();
        Schedule.insert(Schedule.end(), temp);
    }
    std::sort(Schedule.begin(),Schedule.end());

    for(auto a: Schedule){
        cout << a << endl;
    }


}