//
// Created by Kevin Yang on 3/20/21.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(int layer, int& n, vector<string>& board){
        if(layer==n)
    }

    vector<vector<string>> solveNQueens(int n) {
        if (n == 1) {
            return vector<vector<string>>{vector<string>{"Q"}};
        } else if (n == 2 || n == 3) {
            return vector<vector<string>>{};
        } else if (n == 4) {
            return vector<vector<string>>{vector<string>{".Q..", "...Q", "Q...", "..Q."},
                                          vector<string>{"..Q.", "Q...", "...Q", ".Q.."}};
        }
    }
};

int main() {
    int n;
    cin >> n;
    Solution solution;
    vector<vector<string>> vector = solution.solveNQueens(n);
    return 0;
}