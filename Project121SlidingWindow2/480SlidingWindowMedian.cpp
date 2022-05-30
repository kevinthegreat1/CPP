//
// Created by Kevin Yang on 11/27/21.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k) {
        int i, n = nums.size();
        bool odd = k % 2;
        multiset<int> window = {nums.begin(), nums.begin() + k};
        auto mid = next(window.begin(), (k * 0.5));
        vector<double> answer;
        if (odd) {
            answer.push_back(double(*mid));
        } else {
            answer.push_back(((double) (*mid) * 0.5 + (double) (*next(mid, -1)) * 0.5));
        }
        for (i = 0; i < n - k; i++) {
            window.insert(nums[i + k]);
            if (nums[i + k] < *mid) {
                mid--;
            }
            if (nums[i] <= *mid) {
                mid++;
            }
            window.erase(window.find(nums[i]));
            if (odd) {
                answer.push_back(double(*mid));
            } else {
                answer.push_back(((double) (*mid) * 0.5 + (double) (*next(mid, -1)) * 0.5));
            }
        }
        return answer;
    }
};

int main(){
    Solution solution;
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    vector<double> answer = solution.medianSlidingWindow(nums,3);
    return 0;
}