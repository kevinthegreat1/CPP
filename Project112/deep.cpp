//
// Created by Kevin Yang on 5/15/21.
//

#include <iostream>

using namespace std;

int main() {
    int h, s;
    string commands;
    cin >> h >> s >> commands;
    for (char c:commands) {
        if (c == 'u' && s > 0) {
            s--;
        } else if (c == 'd' && s < h) {
            s++;
        }
    }
    cout << s;
    return 0;
}