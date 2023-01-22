//
// Created by Kevin Yang on 12/28/22.
//

#include <iostream>
#include <set>

using namespace std;

const int N = 100001;
int m;
int n;

bool comp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second || (a.second == b.second && a.first < b.first);
}

void solve() {
    cin >> n;
    string parentheses[N];
    set<pair<int, int>, decltype(comp) *> extraParentheses(comp);
    for (int i = 0; i < n; i++) {
        cin >> parentheses[i];
        int left = 0, right = 0;
        for (char c: parentheses[i]) {
            switch (c) {
                case '(':
                    left++;
                    break;
                case ')':
                    if (left > 0) {
                        left--;
                    } else {
                        right++;
                    }
                    break;
            }
        }
        extraParentheses.insert({i, right - left});
    }
    string ansString;
    int i = 0;
    int left = 0, right = 0, ans = 0;
    for (pair<int, int> extraParenthesis: extraParentheses) {
        ansString += parentheses[extraParenthesis.first];
        for (; i < ansString.size(); i++) {
            switch (ansString[i]) {
                case '(':
                    left++;
                    break;
                case ')':
                    if (left > 0) {
                        left--;
                        ans++;
                    } else {
                        right++;
                    }
                    break;
            }
        }
    }
    cout << (ans << 1) << endl;
}

int main() {
    cin >> m;
    for (int i = 0; i < m; i++) {
        solve();
    }
    return 0;
}