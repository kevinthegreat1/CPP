//
// Created by Kevin Yang on 12/12/21.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int constrainedSubsetSum(vector<int> &nums, int k) {
        int n = (int) nums.size(), answer;
        vector<int> dp(n, 0);
        map<int, int> count;
        answer = dp[0] = nums[0];
        count[dp[0]]++;
        for (int i = 1, cur = 1; i < n; count[dp[i]]++, cur++, i++) {
            auto it = --count.end();
            dp[i] = max(nums[i], nums[i] + it->first);
            while (cur >= k) {
                count[dp[i - cur]]--;
                if (count[dp[i - cur]] == 0) {
                    count.erase(dp[i - cur]);
                }
                cur--;
            }
            answer = max(answer, dp[i]);
        }
        return answer;
    }
};

int main(){
    Solution solution;
    vector<int>nums={10,2,-10,5,20};
    int answer = solution.constrainedSubsetSum(nums,2);
    return 0;
}