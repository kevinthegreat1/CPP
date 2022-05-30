//
// Created by Kevin Yang on 12/17/21.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
private:
    int dfs(vector<string> &stickers, const map<char, int> &target) {
        int t = INT32_MAX - 1;
        for (string sticker: stickers) {
            map<char, int> newTarget = target;
            for (char c: sticker) {
                if (newTarget.find(c) != newTarget.end()) {
                    newTarget[c] > 1 ? newTarget[c]-- : newTarget.erase(c);
                }
            }
            if (newTarget.empty()) {
                return 1;
            }
            if (newTarget == target) {
                continue;
            }
            t = min(dfs(stickers, newTarget) + 1, t);
        }
        return t;
    }

public:
    int minStickers(vector<string> &stickers, string target) {
        map<char, int> t;
        for (char c: target) {
            t[c]++;
        }
        int ans = dfs(stickers, t);
        return ans == INT32_MAX - 1 ? -1 : ans;
    }
};

int main(){
    Solution solution;
    vector<string> stickers{"a","enemy","material","whose","twenty","describe","magnet","put","hundred","discuss"};
    int answer = solution.minStickers(stickers,"separatewhich");
    return 0;
}