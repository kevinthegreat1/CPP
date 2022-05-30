//
// Created by Kevin Yang on 3/28/21.
//

#include <iostream>
#include <vector>

using namespace std;

int VerticalHeight(vector<vector<bool>> &board, int row, int col) {
    int i;
    for (i = 0; row - i >= 0; i++) {
        if (!board[row - i][col]) {
            break;
        }
    }
    return i;
}

int VerticalArea(vector<int> vector) {
    int n, count = 1, answer = 0, i, j;
    n = vector.size();
    for (i = 0; i < n; i++) {
        answer = max(vector[i], answer);
    }
    for (i = 0; i < n; i++, count = 1) {
        for (j = i + 1; j < n; j++) {
            if (vector[j] >= vector[i]) {
                count++;
            } else {
                answer = max(vector[i] * count, answer);
                break;
            }
        }
        answer = max(vector[i] * count, answer);
        for (j = i - 1; j >= 0; j--) {
            if (vector[j] >= vector[i]) {
                count++;
            } else {
                answer = max(vector[i] * count, answer);
                break;
            }
        }
        answer = max(vector[i] * count, answer);
    }
    return answer;
}

int main() {
    bool t;
    int n, m, answer = 0, i, j;
    cin >> n >> m;
    vector<vector<bool>> board(n, vector<bool>(m));
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cin >> t;
            board[i][j] = t;
        }
    }
    vector<int> vector;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            vector.push_back(VerticalHeight(board, i, j));
        }
        answer = max(VerticalArea(vector), answer);
        vector.clear();
    }
    cout<<answer;
    return 0;
}