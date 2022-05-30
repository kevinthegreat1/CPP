//
// Created by Kevin Yang on 1/1/22.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        size_t pos;
        while ((pos = s.find(' ')) != string::npos) {
            string t = s.substr(0, pos);
            while (t[0] == ' ') {
                t.erase(t.begin());
            }
            while (t[t.size() - 1] == ' ') {
                t.erase(t.end() - 1);
            }
            if (!t.empty()) {
                v.push_back(s.substr(0, pos));
            }
            s.erase(0, pos + 1);
        }
        reverse(v.begin(), v.end());
        string ans;
        for (const string& word: v) {
            ans += word + " ";
        }
        ans.erase(ans.end() - 1);
        return ans;
    }
};

int main(){
    Solution solution;
    cout<<solution.reverseWords("  hello world  ");
}