//
// Created by Kevin Yang on 3/23/21.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int i, j, k;
        if (p == s) {
            return true;
        }
        if (p.empty()) {
            return false;
        }
        for (i = 0; i < p.size(); i++) {
            if (p[i] == '?' || p[i] == '*') {
                break;
            }
        }
        if (i == p.size()) {
            return false;
        }
        for (i = 0, j = 0; i < p.size(); i++, j++) {
            if (p[i] == s[j] || (p[i] == '?' && j < s.size())) {
                continue;
            } else if (p[i] == '*') {
                while (p[i + 1] == '*') {
                    i++;
                }
                for (k = j; k <= s.size(); k++) {
                    if (isMatch(s.substr(k, s.size()), p.substr(i + 1, p.size()))) {
                        return true;
                    }
                }
                return false;
            } else {
                return false;
            }
        }
        if (p.size() == s.size()) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    string s, p;
    cin >> s >> p;
    Solution solution;
    cout<<solution.isMatch(s, p);
    return 0;
}