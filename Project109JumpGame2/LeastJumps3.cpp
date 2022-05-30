//
// Created by Kevin Yang on 4/24/21.
//

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int main() {
    int n, i;
    cin >> n;
    vector<int> arr(n);
    unordered_map<int, vector<int>> index;
    for (i = 0; i < n; i++) {
        cin >> arr[i];
        index[arr[i]].push_back(i);
    }
    vector<bool> visited(n, false);
    queue<pair<int, int>> queue;
    queue.push(pair<int,int>{0,0});
    visited[0] = true;
    while (!queue.empty()) {
        i = queue.front().first;
        int step = queue.front().second;
        queue.pop();
        vector<int> t = index[arr[i]];
        t.push_back(i + 1);
        t.push_back(i - 1);
        for (int j:t) {
            if (j > 0 && j < n && !visited[j]) {
                if (j == n - 1) {
                    cout << step + 1;
                }
                visited[j] = true;
                queue.push(pair<int, int>{j, step + 1});
            }
        }
        index[arr[i]] = {};
    }
    return 0;
}