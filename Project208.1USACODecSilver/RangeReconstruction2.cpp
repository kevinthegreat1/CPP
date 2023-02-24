//
// Created by Kevin Yang on 1/28/23.
//

#include <iostream>

using namespace std;

const int N = 301;

int main() {
    int n;
    int arr[N][N];
    int minAndMax[N][2];
    int ans[N];
    int minInAns = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j + i < n; j++) {
            cin >> arr[i][j];
        }
        minAndMax[i][0] = INT32_MAX;
    }
    ans[0] = 0;
    ans[1] = arr[0][1];
    minAndMax[0][0] = 0;
    minAndMax[0][1] = ans[1];
    minAndMax[1][0] = ans[1];
    minAndMax[1][1] = ans[1];
    // Calculate the (i+1)th element of ans
    for (int i = 1; i < n - 1; i++) {
        int tempNewAns;
        tempNewAns = ans[i] + arr[i][1];
        bool sign = true;
        for (int j = 0; j < i; j++) {
            if (max(tempNewAns, minAndMax[j][1]) - min(tempNewAns, minAndMax[j][0]) != arr[j][i + 1 - j]) {
                sign = false;
                break;
            }
        }
        if (sign) {
            ans[i + 1] = ans[i] + arr[i][1];
            minAndMax[i + 1][0] = ans[i + 1];
            for (int j = 0; j <= i + 1; j++) {
                minAndMax[j][1] = max(minAndMax[j][1], ans[i + 1]);
            }
        } else {
            ans[i + 1] = ans[i] - arr[i][1];
            minAndMax[i + 1][1] = ans[i + 1];
            for (int j = 0; j <= i + 1; j++) {
                minAndMax[j][0] = min(minAndMax[j][0], ans[i + 1]);
            }
        }
        minInAns = min(minInAns, ans[i + 1]);
    }
    for (int i = 0; i < n; i++) {
        ans[i] -= minInAns;
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