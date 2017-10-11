#include <iostream>
#include <vector>
#include <algorithm>
#include "concert.h"

using namespace std;

/*****************************************************************
 * Driver for the Concert Class
 ****************************************************************/
int main(int argc, char **argv) {
    //Create Schedule of Concerts
    vector<Concert> Schedule;

    //Create some entries
    time_t now = time(nullptr);
    tm *ltm = localtime(&now);
    Concert A = Concert();
    Concert B = Concert("Wiz Khalifa and Li'l Wayne", {"Morgan Freeman", "Beyonce"}, 3, *ltm);
    Concert C = Concert("Kanye", {"Morgan Freeman", "Beyonce"}, 5, *ltm);
    //Insert Entries
    Schedule.insert(Schedule.begin(), A);
    Schedule.insert(Schedule.end(), B);
    Schedule.insert(Schedule.end(), C);

    //Create more entries faster
    for (int i = 0; i < 10; i++) {
        Concert temp = Concert();
        Schedule.insert(Schedule.end(), temp);
    }
    //sort entries
    std::sort(Schedule.begin(), Schedule.end());
    //print Schedule
    for (const auto &a: Schedule) {
        cout << a << endl;
    }
}