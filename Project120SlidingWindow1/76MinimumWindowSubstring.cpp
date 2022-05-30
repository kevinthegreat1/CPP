//
// Created by Kevin Yang on 11/24/21.
//

#include <iostream>
#include <map>

using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) {
            return "";
        }
        if (s == t) {
            return s;
        }
        int i = 0, j;
        map<char, int> scount, tcount;
        for (char t1: t) {
            tcount[t1]++;
        }
        int count = 0;
        string answer;
        for (j = 0; j < s.size(); j++) {
            scount[s[j]]++;
            if (scount[s[j]] <= tcount[s[j]]) {
                count++;
            }
            while (scount[s[i]] > tcount[s[i]]) {
                scount[s[i++]]--;
            }
            if (count == t.size()) {
                answer = answer.empty() || j - i + 1 < answer.size() ? s.substr(i, j - i + 1) : answer;
            }
        }
        return answer;
    }
};

int main(){
    Solution solution;
    solution.minWindow("erbrbgb","br");
}