//
// Created by Kevin Yang on 3/16/21.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        if (n == 1) {
            return vector<vector<string>>{vector<string>{"Q"}};
        } else if (n == 2 || n == 3) {
            return vector<vector<string>>{};
        } else if (n == 4) {
            return vector<vector<string>>{vector<string>{".Q..", "...Q", "Q...", "..Q."},
                                          vector<string>{"..Q.", "Q...", "...Q", ".Q.."}};
        }
        int i, j;
        vector<int> permutation;
        vector<string> dot(n), board(n);
        vector<vector<string>> answer;
        for (i = 0; i < n; i++) {
            permutation.push_back(i);
            for (j = 0; j < n; j++) {
                dot[i] += '.';
            }
        }
        bool flag, exit = true;
        while (exit) {
            next_permutation(permutation.begin(), permutation.end());
            for (i = 1, flag = true, exit = false; i < n; i++) {
                if (permutation[i] - permutation[i - 1] != 1) {
                    exit = true;
                }
                for (j = 0; j < n; j++) {
                    if (i != j && (permutation[i] - i == permutation[j] - j ||
                                   permutation[i] - (n - i) == permutation[j] - (n - j))) {
                        flag = false;
                    }
                }
            }
            if (flag) {
                for (i = 0, board = dot; i < n; i++) {
                    board[i][permutation[i]] = 'Q';
                }
                answer.push_back(board);
            }
        }
        return answer;
    }
};

int main() {
    int n;
    cin >> n;
    Solution solution;
    vector<vector<string>> vector = solution.solveNQueens(n);
    return 0;
}