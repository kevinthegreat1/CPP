//
// Created by Kevin Yang on 12/12/21.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minMoves(vector<int> &nums, int k) {
        int i, mid, left, answer = INT32_MAX;
        vector<int> ones, sum(1);
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                ones.push_back(i - (int) ones.size());
                sum.push_back(sum.back() + ones.back());
            }
        }
        for (i = k - 1; i < ones.size(); i++) {
            left = i - k + 1;
            mid = (left + i) >> 1;
            answer = min(answer, ones[mid] * (mid - left) - (sum[mid] - sum[left]) + sum[i + 1] - sum[mid + 1] -
                                 ones[mid] * (i - mid));
        }
        return answer;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1,0,0,0,0,0,1,1};
    int answer = solution.minMoves(nums, 3);
    return 0;
}