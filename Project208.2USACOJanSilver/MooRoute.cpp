//
// Created by Kevin Yang on 1/28/23.
//

#include <iostream>

using namespace std;

const int N = 100001;
int n;
int arr[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    int cur = 0;
    bool direction = true;
    string route;
    while (true) {
        int prev = direction ? cur : cur + 1;
        int next = direction ? cur + 1 : cur;
        if (prev <= 0 || next <= 0) {
            direction = true;
        } else if (prev > n || next > n) {
            direction = false;
        } else if (arr[prev] >= 1 && arr[next] <= 1) {
            direction = !direction;
        }
        if (arr[prev] == 0 && arr[next] == 0) {
            cout << route << endl;
            break;
        }
        arr[direction ? cur + 1 : cur]--;
        cur += direction ? 1 : -1;
        route += direction ? 'R' : 'L';
    }
    return 0;
}