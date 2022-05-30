//
// Created by Kevin Yang on 4/3/22.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool possibleToStamp(vector<vector<int>> &grid, int stampHeight, int stampWidth) {
        int n = (int) grid.size(), m = (int) grid[0].size();
        set<pair<int, int>> occupiedX, occupiedY;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    occupiedX.insert({j, i});
                    occupiedY.insert({i, j});
                }
            }
        }
        vector<int> prevOccupiedX(n, -1);
        for (pair<int, int> occupiedCell: occupiedX) {
            int distance = occupiedCell.first - prevOccupiedX[occupiedCell.second];
            if (1 < distance && distance <= stampWidth) {
                return false;
            }
            prevOccupiedX[occupiedCell.second] = occupiedCell.first;
        }
        for (int prev: prevOccupiedX) {
            int distance = m - prev;
            if (1 < distance && distance <= stampWidth) {
                return false;
            }
        }
        vector<int> prevOccupiedY(m, -1);
        for (pair<int, int> occupiedCell: occupiedY) {
            int distance = occupiedCell.first - prevOccupiedY[occupiedCell.second];
            if (1 < distance && distance <= stampHeight) {
                return false;
            }
            prevOccupiedY[occupiedCell.second] = occupiedCell.first;
        }
        for (int prev: prevOccupiedY) {
            int distance = n - prev;
            if (1 < distance && distance <= stampHeight) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid1 = {{1, 0, 0, 0},
                                 {1, 0, 0, 0},
                                 {1, 0, 0, 0},
                                 {1, 0, 0, 0},
                                 {1, 0, 0, 0}};
    vector<vector<int>> grid2 = {{1, 0, 0, 0},
                                 {0, 1, 0, 0},
                                 {0, 0, 1, 0},
                                 {0, 0, 0, 1}};
    vector<vector<int>> grid3 = {{1, 1, 1},
                                 {1, 1, 1},
                                 {1, 1, 1},
                                 {1, 1, 1},
                                 {1, 1, 1},
                                 {1, 1, 1}};
    vector<vector<int>> grid4 = {{0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0},
                                 {0, 0, 1, 0, 0},
                                 {0, 0, 0, 0, 1},
                                 {0, 0, 0, 1, 1}};
    cout << solution.possibleToStamp(grid4, 2, 2);
    return 0;
}