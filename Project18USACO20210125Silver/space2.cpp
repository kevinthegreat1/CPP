#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, x, ans1, ans2, y, i, j, t1;
    vector<int> t2;
    vector<vector<int>> beauty;
    cin >> n;
    for (i = 0; i < n; i++) {
        for (j = 0, t2.clear(); j < n; j++) {
            cin >> t1;
            t2.push_back(t1);
        }
        beauty.push_back(t2);
    }
    for (i = 0, x = 0; i < n; i++) {
        for (j = 0, ans1 = 0, ans2 = 0; j < n; j++) {
            if (j % 2 == 0) {
                ans1 += beauty[i][j];
            } else {
                ans2 += beauty[i][j];
            }
        }
        x += max(ans1, ans2);
    }
    for (i = 0, y = 0; i < n; i++) {
        for (j = 0, ans1 = 0, ans2 = 0; j < n; j++) {
            if (j % 2 == 0) {
                ans1 += beauty[j][i];
            } else {
                ans2 += beauty[j][i];
            }
        }
        y += max(ans1, ans2);
    }
    cout << max(x, y);
    return 0;
}