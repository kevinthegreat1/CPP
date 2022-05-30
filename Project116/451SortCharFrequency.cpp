//
// Created by Kevin Yang on 7/3/21.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        int n = s.size(), i, j;
        vector<int> count(75, 0);
        vector<vector<char>> frequency(n+1, vector<char>());
        for (i = 0; i < n; i++) {
            count[s[i] - '0']++;
        }
        for (i = 0; i < 75; i++) {
            if (count[i] != 0) {
                frequency[count[i]].push_back(i + '0');
            }
        }
        string answer;
        for (i = n; i >= 0; i--) {
            for (char character:frequency[i]) {
                for (j = 0; j < i; j++) {
                    answer += character;
                }
            }
        }
        return answer;
    }
};

int main(){
    Solution solution;
    cout << solution.frequencySort("eeeee");
    return 0;
}