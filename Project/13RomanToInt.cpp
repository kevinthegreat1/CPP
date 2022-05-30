//
// Created by Kevin Yang on 5/8/21.
//

#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<string, int> map = {{"I",  1},
                                {"IV", 3},
                                {"V",  5},
                                {"IX", 8},
                                {"X",  10},
                                {"XL", 30},
                                {"L",  50},
                                {"XC", 80},
                                {"C",  100},
                                {"CD", 300},
                                {"D",  500},
                                {"CM", 800},
                                {"M",  1000}};
        int ans = map[s.substr(0, 1)];
        string one, two;
        for (int i = 1; i < s.size(); i++) {
            one = s.substr(i, 1);
            two = s.substr(i - 1, 2);
            ans += map[two] ? map[two] : map[one];
        }
        return ans;
    }
};