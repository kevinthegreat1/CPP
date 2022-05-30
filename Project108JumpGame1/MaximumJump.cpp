//
// Created by Kevin Yang on 4/17/21.
//

#include <iostream>
#include <vector>

using namespace std;

bool comp(pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}

int main() {
    int n, i, j;
    cin >> n;
    vector<pair<int, int>> maxJump(n);
    for (i = 0; i < n; i++) {
        maxJump[i].first = i;
        cin >> maxJump[i].second;
        maxJump[i].second += i;
    }
    sort(maxJump.begin(), maxJump.end(), comp);
    for (j = 0, i = 1; i < n; i++) {
        if (maxJump[j].second >= maxJump[i].first) {
            j = i;
        }
    }
    if (j == n-1) {
        cout << true;
    } else {
        cout << false;
    }
    return 0;
}