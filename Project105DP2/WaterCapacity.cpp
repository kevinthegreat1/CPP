//
// Created by Kevin Yang on 4/2/21.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, largest = 0, count = 0, i, j, t;
    cin >> n;
    vector<int> board;
    for (i = 0; i < n; i++) {
        cin >> t;
        board.push_back(t);
        largest = max(t, largest);
    }
    for (i = 0; i < largest; i++) {
        while (true) {
            if (board.back() > 0) {
                break;
            }
            board.pop_back();
        }
        for (j = 0; board[j] == 0; j++) {}
        j++;
        for (; j < board.size() - 1; j++) {
            if (board[j] == 0) {
                count++;
            }
        }
        for (j = 0; j < board.size(); j++) {
            board[j] == 0 ?: board[j]--;
        }
    }
    cout<<count;
    return 0;
}