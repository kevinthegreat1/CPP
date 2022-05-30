//
// Created by Kevin Yang on 5/29/21.
//

#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int main() {
    int n, m, startI, startJ, i, j, t;
    cin >> n >> m;
    vector<vector<bool>> orchid(n+2, vector<bool>(m+2,true));
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            cin >> t;
            if (t == 1) {
                orchid[i][j] = false;
            } else if (t == 2) {
                orchid[i][j] = true;
            } else if (t == 6) {
                startI = i;
                startJ = j;
            }
        }
    }
    queue<pair<int,int>> queue;
    set<pair<int,int>> visited;
    queue.push(pair<int,int>(startI,startJ));
    while(!queue.empty()){
        pair<int,int> cur=queue.front();
        queue.pop();
        visited.insert(cur);
        if(!orchid[cur.first+1][cur.second] && visited.find(pair<int,int>(cur.first+1,cur.second))==visited.end()){
            queue.push(pair<int,int>(cur.first+1,cur.second));
        }
        if(!orchid[cur.first-1][cur.second] && visited.find(pair<int,int>(cur.first-1,cur.second))==visited.end()){
            queue.push(pair<int,int>(cur.first-1,cur.second));
        }
        if(!orchid[cur.first][cur.second+1] && visited.find(pair<int,int>(cur.first,cur.second+1))==visited.end()){
            queue.push(pair<int,int>(cur.first,cur.second+1));
        }
        if(!orchid[cur.first][cur.second-1] && visited.find(pair<int,int>(cur.first,cur.second-1))==visited.end()){
            queue.push(pair<int,int>(cur.first,cur.second-1));
        }
    }
    cout<<visited.size();
    return 0;
}