//
// Created by Kevin Yang on 4/17/21.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, i, j;
    cin >> n;
    vector<int> nums(n);
    vector<int> maxJumps(n, 1);
    for (i = 0; i < n; i++) {
        cin >> nums[i];
    }
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (nums[i] == nums[j]) {
                maxJumps[i] = j - i;
            }
        }
    }
    int jumpTo = 0, furthest = 0, jumps = 0;
    for (i = 0; i < n - 1; i++) {
        furthest = max(maxJumps[i] + i, furthest);
        if (jumpTo == i) {
            jumps++;
            jumpTo = furthest;
        }
    }
    cout<<jumps;
    return 0;
}