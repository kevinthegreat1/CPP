//
// Created by Kevin Yang on 2/19/23.
//

#include <iostream>
#include <vector>

using namespace std;

const int N = 101;
const int M = 11;
int n, m;

int countOnes(int num) {
    int cnt = 0;
    while (num > 0) {
        if (num & 1) {
            cnt++;
        }
        num >>= 1;
    }
    return cnt;
}

int hashMap(const char row[M]) {
    int res = 0;
    for (int i = 0; i < m; i++) {
        res = res * 2 + (row[i] == 'M' ? 1 : 0);
    }
    return res;
}

bool conflict(int a, int b) {
    return (a & b) != 0;
}

bool conflict(int a) {
    if (conflict(a << 1, a)) return true;
    if (conflict(a >> 1, a)) return true;
    if (conflict(a << 2, a)) return true;
    if (conflict(a >> 2, a)) return true;
    return false;
}

vector<int> allStatus;

void init() {
    for (int i = 0; i < (1 << m); i++) {
        if (!conflict(i)) {
            allStatus.push_back(i);
        }
    }
}

int main() {
    cin >> n >> m;
    char map[N][M];
    int hashedMap[N];
    for (int i = 0; i < n; i++) {
        cin >> map[i];
        hashedMap[i] = hashMap(map[i]);
    }
    init();
    int dp[N][1 << M][1 << M];
    for (int i: allStatus) {
        for (int j: allStatus) {
            if (conflict(i, j) || conflict(i, hashedMap[0]) || conflict(j, hashedMap[1])) continue;
            dp[0][i][j] = countOnes(i);
        }
    }
    int ans;
    for (int i = 1; i < n; i++) {
        for (int j: allStatus) {
            if (conflict(j, hashedMap[i])) continue;
            for (int k: allStatus) {
                if (conflict(j, k) || conflict(k, hashedMap[i - 1])) continue;
                for (int l: allStatus) {
                    if (conflict(j, l) || conflict(k, l) || conflict(l, hashedMap[i - 2])) continue;
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][k][l] + countOnes(j));
                    if (i == n - 1) {
                        ans = max(ans, dp[i][j][k]);
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}


