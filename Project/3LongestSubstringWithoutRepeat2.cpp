//
// Created by Kevin Yang on 5/15/21.
//

#include <iostream>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, longest = 0, n = s.size(), i;
        map<char, int> map;
        for (i = 0; i < n; i++) {
            char c = s[i];
            if (map.find(c) != map.end()) {
                start = max(map.at(c) + 1, start);
            }
            longest = max(i - start + 1, longest);
            map.erase(c);
            map.insert(pair<char, int>{c, i});
        }
        return longest;
    }
};

int main(){
    Solution solution;
    cout<<solution.lengthOfLongestSubstring(string{"abcabcbb"});
    return 0;
}