//
// Created by Kevin Yang on 4/10/21.
//

#include <iostream>
#include <vector>

using namespace std;

bool comp(pair<int,int> a, pair<int,int> b) {
    return a.second < b.second;
}

int main() {
    int n, count = 1, i, j;
    cin >> n;
    vector<pair<int, int>> intervals(n);
    for (i = 0; i < n; i++) {
        cin >> intervals[i].first >> intervals[i].second;
    }
    sort(intervals.begin(), intervals.end(), comp);
    for (i = 0, j = 1; j < n; j++) {
        if (intervals[i].second < intervals[j].first) {
            count++;
            i = j;
        }
    }
    cout << count;
    return 0;
}