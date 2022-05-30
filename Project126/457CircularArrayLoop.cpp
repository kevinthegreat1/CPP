//
// Created by Kevin Yang on 1/16/22.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool circularArrayLoop(vector<int> &nums) {
        set<int> visited;
        for (int i = 0; i < nums.size(); i++) {
            if (visited.find(i) != visited.end()) {
                continue;
            }
            set<int> cur;
            int j = i, last;
            bool positive = nums[i] > 0;
            cur.insert(i);
            while (true) {
                if ((nums[j] > 0 && !positive) || (nums[j] < 0 && positive)) {
                    break;
                }
                last = j;
                j = (j + nums[j]) % (int) nums.size();
                if (j < 0) {
                    j += (int) nums.size();
                }
                if (j == last) {
                    break;
                }
                if (cur.find(j) != cur.end()) {
                    return true;
                }
                cur.insert(j);
            }
            visited.insert(cur.begin(), cur.end());
        }
        return false;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2,2,-2,2};
    cout << solution.circularArrayLoop(nums);
    return 0;
}