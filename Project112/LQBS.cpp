//
// Created by Kevin Yang on 5/15/21.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

string board[100];
vector<pair<int,int>> Ls;
set<pair<int,int>> curVisitedLs;
set<pair<int,int>> visitedLs;

int search(int i, int j) {
    int count = 0, t;
    if (board[i][j] == 'L') {
        if (curVisitedLs.find(pair<int, int>{i, j}) != curVisitedLs.end()) {
            return -1;
        } else if (visitedLs.find(pair<int, int>{i, j}) != visitedLs.end()) {
            return 0;
        }
        curVisitedLs.insert(pair<int, int>{i, j});
        visitedLs.insert(pair<int, int>{i, j});
        if (board[i - 1][j] == 'Q') {
            t = search(i - 1, j);
            if (t == -1) {
                return -1;
            }
            count += t;
        }
        if (board[i + 1][j] == 'Q') {
            t = search(i + 1, j);
            if (t == -1) {
                return -1;
            }
            count += t;
        }
        if (board[i][j - 1] == 'Q') {
            t = search(i, j - 1);
            if (t == -1) {
                return -1;
            }
            count += t;
        }
        if (board[i][j + 1] == 'Q') {
            t = search(i, j + 1);
            if (t == -1) {
                return -1;
            }
            count += t;
        }
    } else if (board[i][j] == 'Q') {
        if (board[i - 1][j] == 'B') {
            t = search(i - 1, j);
            if (t == -1) {
                return -1;
            }
            count += t;
        }
        if (board[i + 1][j] == 'B') {
            t = search(i + 1, j);
            if (t == -1) {
                return -1;
            }
            count += t;
        }
        if (board[i][j - 1] == 'B') {
            t = search(i, j - 1);
            if (t == -1) {
                return -1;
            }
            count += t;
        }
        if (board[i][j + 1] == 'B') {
            t = search(i, j + 1);
            if (t == -1) {
                return -1;
            }
            count += t;
        }
    } else if (board[i][j] == 'B') {
        if (board[i - 1][j] == 'S') {
            t = search(i - 1, j);
            if (t == -1) {
                return -1;
            }
            count += t;
        }
        if (board[i + 1][j] == 'S') {
            t = search(i + 1, j);
            if (t == -1) {
                return -1;
            }
            count += t;
        }
        if (board[i][j - 1] == 'S') {
            t = search(i, j - 1);
            if (t == -1) {
                return -1;
            }
            count += t;
        }
        if (board[i][j + 1] == 'S') {
            t = search(i, j + 1);
            if (t == -1) {
                return -1;
            }
            count += t;
        }
    } else if (board[i][j] == 'S') {
        count++;
        if (board[i - 1][j] == 'L') {
            t = search(i - 1, j);
            if (t == -1) {
                return -1;
            }
            count += t;
        }
        if (board[i + 1][j] == 'L') {
            t = search(i + 1, j);
            if (t == -1) {
                return -1;
            }
            count += t;
        }
        if (board[i][j - 1] == 'L') {
            t = search(i, j - 1);
            if (t == -1) {
                return -1;
            }
            count += t;
        }
        if (board[i][j + 1] == 'L') {
            t = search(i, j + 1);
            if (t == -1) {
                return -1;
            }
            count += t;
        }
    }
    return count;
}

int main() {
    int n, m, count = 0, i, j;
    cin >> n >> m;
    for (i = 0; i < n; i++) {
        cin >> board[i];
        for (j = 0; j < n; j++) {
            if (board[i][j] == 'L') {
                Ls.emplace_back(i, j);
            }
        }
    }
    for (pair<int, int> L:Ls) {
        i = search(L.first, L.second);
        if (i == -1) {
            cout << -1;
            return 0;
        }
        count += i;
        curVisitedLs.clear();
    }
    cout << count;
    return 0;
}