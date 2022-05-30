//
// Created by Kevin Yang on 11/24/21.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() < 10) {
            return vector<string>{};
        }
        set<string> count, answers;
        int i;
        string t;
        for (i = 0; i <= s.size() - 10; i++) {
            t = s.substr(i, 10);
            if (count.find(t) == count.end()) {
                count.insert(t);
            } else {
                answers.insert(t);
            }
        }
        return {answers.begin(), answers.end()};
    }
};

int main() {
    Solution solution;
    vector<string> a = solution.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    return 0;
}