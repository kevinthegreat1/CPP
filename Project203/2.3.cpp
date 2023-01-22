//
// Created by Kevin Yang on 12/28/22.
//

#include <iostream>

using namespace std;

const int N = 100001;
int m;
int n;

void solve() {
    cin >> n;
    string parentheses[N];
    pair<int, int> extraParentheses[N];
    int validPairs[N];
    memset(validPairs, 0, sizeof(validPairs));
    for (int i = 0; i < n; i++) {
        cin >> parentheses[i];
        for (char c: parentheses[i]) {
            switch (c) {
                case '(':
                    extraParentheses[i].first++;
                    break;
                case ')':
                    if (extraParentheses[i].first > 0) {
                        extraParentheses[i].first--;
                        validPairs[i]++;
                    } else {
                        extraParentheses[i].second++;
                    }
                    break;
            }
        }
    }
}

int main() {
    cin >> m;
    for (int i = 0; i < m; i++) {
        solve();
    }
    return 0;
}