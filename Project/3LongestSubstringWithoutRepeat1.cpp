//
// Created by Kevin Yang on 5/15/21.
//

#include <iostream>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size(), longest=0, i, length;
        if(n==1){
            return 1;
        }
        set<char> cur;
        for (i = 0, length=0; i < n; i++,length++) {
            if(cur.find(s[i]) != cur.end()){
                longest=max(length,longest);
                cur.clear();
                length=0;
            }
            cur.insert(s[i]);
        }
        longest=max(length,longest);
        return longest;
    }
};

int main(){
    Solution solution;
    cout<<solution.lengthOfLongestSubstring(string{"au"});
    return 0;
}