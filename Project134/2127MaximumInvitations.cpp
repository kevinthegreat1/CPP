//
// Created by Kevin Yang on 3/20/22.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int maximumInvitations(const vector<int> &favorite) {
        int n = (int) favorite.size();
        vector<int> favoriteOf(n);
        for (int fav: favorite) {
            favoriteOf[fav]++;
        }
        queue<int> notFavorited;
        for (int i = 0; i < n; i++) {
            if (favoriteOf[i] == 0) {
                notFavorited.push(i);
            }
        }
        vector<bool> visited(n, false);
        vector<int> longestChain(n, 1);
        while (!notFavorited.empty()) {
            int cur = notFavorited.front();
            notFavorited.pop();
            visited[cur] = true;
            int favCur = favorite[cur];
            longestChain[favCur] = max(longestChain[favCur], longestChain[cur] + 1);
            if (--favoriteOf[favCur] == 0) {
                notFavorited.push(favCur);
            }
        }
        int maxCycle = 0, total = 0;
        for (int cur = 0; cur < n; cur++) {
            if (visited[cur]) {
                continue;
            }
            int favCur = favorite[cur];
            if (favorite[favCur] == cur) {
                total += longestChain[cur] + longestChain[favCur];
                visited[cur] = true, visited[favCur] = true;
            } else {
                int cycle = cur, count = 1;
                for (;; count++) {
                    cycle = favorite[cycle];
                    visited[cycle] = true;
                    if (cycle == cur) {
                        break;
                    }
                }
                maxCycle = max(maxCycle, count);
            }
        }
        return max(maxCycle, total);
    }
};

int main() {
    Solution solution;
    vector<int> favorite1 = {2, 2, 1, 2};
    vector<int> favorite2 = {1, 2, 0};
    vector<int> favorite3 = {3, 0, 1, 4, 1};
    cout << solution.maximumInvitations(favorite3);
    return 0;
}