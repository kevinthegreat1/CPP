//
// Created by Kevin Yang on 7/24/21.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main(){
    int n=9, i, j;
    vector<set<int>> nums={{1,2,3,4},{3,4,5,6,7,8},{7,9},{9}};
    set<int> target;
    for(i=0;i<n;i++){
        target.insert(i);
    }
    vector<set<int>> missing(nums.size(),set<int>());
    for(i=0;i<nums.size();i++){
        set_difference(target.begin(),target.end(),nums[i].begin(),nums[i].end(),missing[i].begin());
    }
    return 0;
}