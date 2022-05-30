//
// Created by Kevin Yang on 7/24/21.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>> &isConnected) {
        unsigned char n = isConnected.size(), count = 0, i, j;
        vector<bool> visited(n, false);
        for (i = 0; i < n; i++) {
            if (visited[i]) {
                continue;
            }
            queue<unsigned char> q;
            q.push(i);
            while (!q.empty()) {
                unsigned char cur = q.front();
                q.pop();
                visited[cur] = true;
                for (j = 0; j < n; j++) {
                    if (isConnected[cur][j] && !visited[j]) {
                        q.push(j);
                    }
                }
            }
            count++;
        }

        return count;
    }
};

int main(){
    Solution solution;
    vector<vector<int>> isConnected={{1,1,0},{1,1,0},{0,0,1}};
    cout<<solution.findCircleNum(isConnected);
    return 0;
}