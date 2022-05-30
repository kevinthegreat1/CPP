//
// Created by Kevin Yang on 5/23/21.
//

#include <iostream>

using namespace std;

int main() {
    int n, k, r, s, c, score = 0, i;
    string opponent, move="";
    cin >> n >> k >> r >> s >> c >> opponent;
    for (i = 0; i < n; i++) {
        if (opponent[i] == 'r') {
            if (move[i - k] != 'c') {
                score += c;
                move+='c';
            } else {
                move+='r';
            }
            continue;
        }
        if (opponent[i] == 's') {
            if (move[i - k] != 'r') {
                score += r;
                move+='r';
            } else {
                move+='s';
            }
            continue;
        }
        if (opponent[i] == 'c') {
            if (move[i - k] != 's') {
                score += s;
                move+='s';
            } else {
                move+='c';
            }
            continue;
        }
    }
    cout<<score;
    return 0;
}