//
// Created by Kevin Yang on 4/10/21.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k, i, j;
    cin >> n;
    vector<int> nums(n + 1, INT32_MAX);
    for (i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cin >> k;
    vector<int> smallest(k, n);
    for (i = 0; i < k; i++) {
        for (i == 0 ? j = 0 : j = smallest[i - 1] + 1; j < n - k + i + 1; j++) {
            nums[j] >= nums[smallest[i]] ?: smallest[i] = j;
        }
        cout << nums[smallest[i]];
        if (i < k - 1) {
            cout << ", ";
        }
    }
    return 0;
}