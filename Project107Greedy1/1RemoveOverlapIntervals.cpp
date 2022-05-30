//
// Created by Kevin Yang on 4/10/21.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, i, count = 0, j;
    cin >> n;
    vector<pair<int, int>> intervals(n);
    for (i = 0; i < n; i++) {
        cin >> intervals[i].first >> intervals[i].second;
    }
    sort(intervals.begin(), intervals.end());
    for (i = 0; i < n; i++) {
        for (j = i + 1; intervals[i].second > intervals[j].first && j < n; j++) {
            count++;
        }
    }
    cout<<n-count-1;
    return 0;
}