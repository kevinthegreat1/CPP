//
// Created by Kevin Yang on 5/23/21.
//

#include <iostream>

using namespace std;

int main() {
    int month, day;
    cin >> month >> day;
    if (month > 1) {
        cout << "Mouse";
        return 0;
    } else if (day > 24) {
        cout << "Mouse";
        return 0;
    } else {
        cout << "Pig";
        return 0;
    }
}