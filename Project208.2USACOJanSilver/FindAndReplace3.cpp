//
// Created by Kevin Yang on 1/28/23.
//

#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int t;
string start, cur, target;
map<char, char> startToTarget;

set<char> visited, finished;
set<char> loops;

int dfs(char v) {
    if (finished.find(v) != finished.end()) { return -1; }
    if (visited.find(v) != visited.end()) {
        loops.insert(v);
        return 0;
    }
    visited.insert(v);
    if (startToTarget.find(v) == startToTarget.end()) { return -1; }
    int res = dfs(startToTarget.find(v)->second);
    if (res == -1) { return -1; }
    else {
        loops.insert(v);
        return res + 1;
    }
}

void solve() {
    startToTarget.clear();
    cin >> start >> target;
    cur = start;
    int count = 0;
    for (int i = 0; i < start.length(); i++) {
        auto it = startToTarget.find(start[i]);
        if (it != startToTarget.end() && it->second != target[i]) {
            cout << -1 << endl;
            return;
        }
        startToTarget.insert(pair<char, char>(cur[i], target[i]));
        if (cur[i] != target[i]) {
            count++;
        }
    }
    for (int i = 0; i < start.length(); i++) {
        visited.clear();
        finished.clear();
        if (loops.find(start[i]) != loops.end()) { continue; }
        if (dfs(start[i]) > 0) {
            count++;
        }
    }
    cout << count << endl;
}

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}