//
// Created by Kevin Yang on 12/5/21.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minMoves(vector<int> &nums, int k) {
        if (k == 1) {
            return 0;
        }
        int n = (int) nums.size(), i, j = -1, l, mid, cost = 0, answer;
        vector<int> zeros, sums{0};
        while (nums[n - 1] == 0) {
            nums.erase(nums.end() - 1);
            n = (int) nums.size();
        }
        for (i = 0; i < n; i++) {
            if (nums[i] == 1) {
                j++;
                zeros.push_back(0);
            } else if (j >= 0) {
                zeros[j]++;
            }
        }
        zeros.erase(zeros.end() - 1);
        int m = (int) zeros.size();
        i = 0, j = k - 2;
        for (l = i; l <= j; l++) {
            cost += zeros[l] * min(l + 1, j - l + 1);
        }
        answer = cost;
        for (int zero: zeros) {
            sums.push_back(sums.back() + zero);
        }
        for (i++, j++; j < m; i++, j++) {
            mid = (i + j) / 2;
            cost -= sums[mid] - sums[i - 1];
            cost += sums[j + 1] - sums[mid + k % 2];
            answer = min(cost, answer);
        }
        return answer;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {0,1,0,0,1,1,0,1,0,1,1,1,1,0,1,0};
    int answer = solution.minMoves(nums, 7);
    return 0;
}