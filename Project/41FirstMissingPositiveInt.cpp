//
// Created by Kevin Yang on 5/8/21.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        int n = nums.size(), i;
        nums.push_back(0);
        for (i = 0; i < n; i++) {
            if (nums[i] == i) {
                continue;
            }
            int cur = nums[i];
            while (cur > 0 && cur <= n && nums[cur] != cur) {
                int next = nums[cur];
                nums[cur] = cur;
                cur = next;
            }
        }
        for (i = 1; i <= n; i++) {
            if (nums[i] != i) {
                return i;
            }
        }
        return i;
    }
};

int main(){
    Solution solution;
    vector<int> v{1};
    cout<<solution.firstMissingPositive(v);
    return 0;
}

//Leetcode 41