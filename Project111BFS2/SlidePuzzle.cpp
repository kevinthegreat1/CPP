//
// Created by Kevin Yang on 5/8/21.
//

#include <iostream>
#include <queue>
#include <set>

using namespace std;

class Solution {
public:
    int slidingPuzzle(vector<vector<int>> &board) {
        int depth = 0, row, col;
        set<vector<vector<int>>> q1, q2, visited;
        q1.insert(board);
        q2.insert(vector<vector<int>>{{1, 2, 3},
                                      {4, 5, 0}});
        visited.insert(board);
        while (!q1.empty() && !q2.empty()) {
            set<vector<vector<int>>> t2;
            for (const vector<vector<int>> &cur : q1) {
                if (q2.find(cur) != q2.end()) {
                    return depth;
                }
                visited.insert(cur);
                bool flag = false;
                for (row = 0; row < 2; row++) {
                    for (col = 0; col < 3 != 0; col++) {
                        if (cur[row][col] == 0) {
                            flag = true;
                            break;
                        }
                    }
                    if (flag) {
                        break;
                    }
                }
                vector<vector<int>> t1 = cur;
                if (row < 1) {
                    swap(t1[row][col], t1[row + 1][col]);
                    if (visited.find(t1) == visited.end()) {
                        t2.insert(t1);
                    }
                } else {
                    swap(t1[row][col], t1[row - 1][col]);
                    if (visited.find(t1) == visited.end()) {
                        t2.insert(t1);
                    }
                }
                t1 = cur;
                if (col < 2) {
                    swap(t1[row][col], t1[row][col + 1]);
                    if (visited.find(t1) == visited.end()) {
                        t2.insert(t1);
                    }
                }
                t1 = cur;
                if (col > 0) {
                    swap(t1[row][col], t1[row][col - 1]);
                    if (visited.find(t1) == visited.end()) {
                        t2.insert(t1);
                    }
                }
            }
            depth++;
            q1 = q2;
            q2 = t2;
        }
        return -1;
    }
};

int main(){
    Solution solution;
    vector<vector<int>> board{{4,1,2},{5,0,3}};
    cout<<solution.slidingPuzzle(board);
    return 0;
}

//Leetcode 773