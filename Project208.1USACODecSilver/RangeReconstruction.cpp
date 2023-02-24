//
// Created by Kevin Yang on 1/28/23.
//

#include <iostream>

using namespace std;

const int N = 301;

int main() {
    int n;
    int arr[N][N];
    int ans[N];
    int minInAns = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j + i < n; j++) {
            cin >> arr[i][j];
        }
    }
    ans[0] = 0;
    ans[1] = arr[0][1];
    bool sign = true;
    for (int i = 1; i < n - 1; i++) {
        if (arr[i - 1][2] <= arr[i - 1][1]) {
            sign = !sign;
        }
        if (sign) {
            ans[i + 1] = ans[i] + arr[i][1];
        } else {
            ans[i + 1] = ans[i] - arr[i][1];
        }
        minInAns = min(minInAns, ans[i + 1]);
    }
    if (minInAns < 0) {
        for (int i = 0; i < n; i++) {
            ans[i] -= minInAns;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i];
        if (i < n - 1) {
            cout << ' ';
        } else {
            cout << endl;
        }
    }
    return 0;
}