//
// Created by Kevin Yang on 5/8/21.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    return vector<int>{i,j};
                }
            }
        }
        return vector<int>{0};
    }
};

int main(){
    Solution solution;
    vector<int> v{2,7,11,15};
    cout<<solution.twoSum(v,9)[0];
    return 0;
}