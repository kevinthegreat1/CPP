//
// Created by Kevin Yang on 12/19/22.
//


#include <iostream>
#include <unordered_set>

using namespace std;

void dfs(unordered_set<int> nums, int cur[], int depth) {
    if (nums.empty()) {
        for (int i = 0; i < depth; i++) {
            cout << cur[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int num: nums) {
        cur[depth] = num;
        unordered_set<int> numsCopy(nums);
        numsCopy.erase(num);
        dfs(numsCopy, cur, depth + 1);
    }
    cur[depth] = 0
}

int main() {
    dfs({1, 2, 3, 4, 5}, new int[5], 0);
    return 0;
}