//
// Created by Kevin Yang on 1/23/22.
//

#include <iostream>
#include <vector>
#include <set>
#include <bit>

using namespace std;

class Solution {
public:
    int minimumDifference(vector<int> &nums) {
        int n = (int) nums.size() >> 1, target = 0, minimum = INT32_MAX;
        for (int num: nums) {
            target += num;
        }
        vector<set<int>> sums1(n + 1, set<int>()), sums2(n + 1, set<int>());
        for (int i = 0; i < (1 << n); i++) {
            int key = __popcount((unsigned) i), count1 = 0, count2 = 0;
            for (int j = 0; j < n; j++) {
                if (((i >> j) & 1) == 1) {
                    count1 += nums[j];
                    count2 += nums[j + n];
                }
            }
            sums1[key].insert(count1);
            sums2[key].insert(count2);
        }
        for (int i = 0; i <= n; i++) {
            for (int sum: sums1[i]) {
                auto it = lower_bound(sums2[n - i].begin(), sums2[n - i].end(), (int) ceil((float) target / 2) - sum);
                if (it != sums2[n - i].end()) {
                    minimum = min(abs((target - 2 * (*it + sum))), minimum);
                }
                if (it != sums2[n - i].begin()) {
                    minimum = min(abs((target - 2 * (*--it + sum))), minimum);
                }
                if (minimum == 0) {
                    return 0;
                }
            }
        }
        return minimum;
    }
};

int main(){
    Solution solution;
    vector<int> nums = {7772197,4460211,-7641449,-8856364,546755,-3673029,527497,-9392076,3130315,-5309187,-4781283,5919119,3093450,1132720,6380128,-3954678,-1651499,-7944388,-3056827,1610628,7711173,6595873,302974,7656726,-2572679,0,2121026,-5743797,-8897395,-9699694};
    cout << solution.minimumDifference(nums);
}