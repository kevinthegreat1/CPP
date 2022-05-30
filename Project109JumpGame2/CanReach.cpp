//
// Created by Kevin Yang on 4/24/21.
//

#include <iostream>
#include <vector>

using namespace std;

bool canReach(vector<int> arr, int start, vector<bool> visited) {
    if (start < 0 || start >= arr.size() || visited[start]) {
        return false;
    }
    if (arr[start]==0) {
        return true;
    }
    visited[start] = true;
    return canReach(arr, start + arr[start], visited) || canReach(arr, start - arr[start], visited);
}

int main() {
    int n, start, i;
    cin >> n;
    vector<int> arr(n);
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> start;
    cout << canReach(arr, start, vector<bool>(n, false));
    return 0;
}