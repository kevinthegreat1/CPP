//
// Created by Kevin Yang on 4/17/21.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, i;
    cin >> n;
    vector<int> maxJumps(n);
    for (i = 0; i < n; i++) {
        cin >> maxJumps[i];
    }
    int jumpTo = 0, furthest = 0, jumps = 0;
    for (i = 0; i < n - 1; i++) {
        furthest = max(maxJumps[i] + i, furthest);
        if (jumpTo == i) {
            jumps++;
            jumpTo = furthest;
        }
    }
    cout << jumps;
    return 0;
}