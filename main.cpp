#include <iostream>
#include <algorithm>
#include "concert.h"

using namespace std;

int main(int argc, char **argv) {
    vector<Concert>Schedule;
    time_t now = time(0);
    tm *ltm = localtime(&now);
    Concert A = Concert("Wiz Khalifa and Li'l Wayne",{"Morgan Freeman","Beyonce"},3,*ltm);
    Schedule.insert(Schedule.begin(),A);
    for(int i = 0; i < 15;i++){
        Concert temp = Concert();
        Schedule.insert(Schedule.end(),temp);
    }
    std::sort(Schedule.begin(),Schedule.end());
    for(auto a: Schedule){
        cout << a.getName() << " " << "Year" << 1970 + a.getDate().tm_year<<endl
        << "Month: "<< 1 + a.getDate().tm_mon<< endl
        << "Day: "<<  a.getDate().tm_mday << endl
        << "Time: "<< 1 + a.getDate().tm_hour << ":"
        << 1 + a.getDate().tm_min << ":"
        << 1 + a.getDate().tm_sec << endl << "\n";
    }


}