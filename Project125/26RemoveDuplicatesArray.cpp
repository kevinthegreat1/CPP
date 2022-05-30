//
// Created by Kevin Yang on 1/1/22.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        for (int i = 1; i < nums.size();) {
            if (nums[i] == nums[i - 1]) {
                nums.erase(nums.begin() + i);
            } else {
                i++;
            }
        }
        return (int) nums.size();
    }
};

int main() {
    Solution solution;
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << solution.removeDuplicates(nums);
}