//
// Created by Kevin Yang on 5/23/21.
//

#include <iostream>
#include <vector>

using namespace std;

int n;

vector<int> next(vector<int> nums) {
    for (int i = (int) nums.size() - 1; i >= 0; i--) {
        if (nums[i] == n) {
            continue;
        } else {
            nums[i]++;
            for (int j = (int) nums.size() - 1; j > i; j--) {
                nums[j] = nums[i];
            }
            return nums;
        }
    }
    return vector<int>{0};
}

int main() {
    int count = 1, mod;
    cin >> n >> mod;
    vector<int> cur(n, 1);
    while (true) {
        cur = next(cur);
        if (cur[0] == 0) {
            cout << count%mod;
            return 0;
        }
        if (cur[0] + cur[1] > cur[n - 1]) {
            count++;
        }
    }
}

//1 2 3 4  5  6  7   8 9 10
//1 3 7 16 39 91 228
// 2 4 9 23 52