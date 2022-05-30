//
// Created by Kevin Yang on 11/27/21.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string> &words) {
        int i, j, n = s.size(), m = words.size(), w = words[0].size();
        map<string, int> wordCount;
        vector<int> answer;
        for (const string &word: words) {
            wordCount[word]++;
        }
        for (i = 0; i < w; i++) {
            map<string, int> sCount;
            int count = 0;
            for (j = i; j + w <= n; j += w) {
                string word = s.substr(j, w);
                sCount[word]++;
                if (sCount[word] <= wordCount[word]) {
                    count++;
                }
                if (j >= m * w) {
                    word = s.substr(j - m * w, w);
                    sCount[word]--;
                    if (sCount[word] < wordCount[word]) {
                        count--;
                    }
                }
                if (count == m) {
                    answer.push_back(j - (m - 1) * w);
                }
            }
        }
        return answer;
    }
};

int main(){
    Solution solution;
    vector<string> words={"foo","bar"};
    vector<int> answer = solution.findSubstring("barfoothefoobarman",words);
    return 0;
}