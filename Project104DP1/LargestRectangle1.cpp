//
// Created by Kevin Yang on 3/21/21.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int x, y, sum, answer = 0, i, j, k, l, m, n;
    bool t1;
    vector<bool> t2;
    vector<vector<bool>> board;
    cin >> x >> y;
    for (i = 0; i < x; i++) {
        for (j = 0, t2.clear(); j < y; j++) {
            cin >> t1;
            t2.push_back(t1);
        }
        board.push_back(t2);
    }
    for (i = 0; i < x; i++) {
        for (j = 0; j < y; j++) {
            for (k = i; k < x; k++) {
                for (l = j; l < y; l++) {
                    sum = 0;
                    for (m = i; m <= k; m++) {
                        for (n = j; n <= l; n++) {
                            sum += board[m][n];
                        }
                    }
                    if (sum == (k - i + 1) * (l - j + 1)) {
                        answer = max(answer, sum);
                    }
                }
            }
        }
    }
    cout << answer;
    return 0;
}