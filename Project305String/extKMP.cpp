/*
给定N个字符串，求他们的最长公共子串
N <= 1000
Length <= 200

3
aabbaabb
abbabbab
babb

abb
*/
//gets()


#include <iostream>
#include <string>

using namespace std;

/* 求解 T 中 next[], 注释参考 GetExtend() */
void GetNext(string &T, int &m, int next[]) {
    int a = 0, p = 0;
    next[0] = m;
    for (int i = 1; i < m; i++) {
        if (i >= p || i + next[i - a] >= p) {
            if (i >= p) {
                p = i;
            }
            while (p < m && T[p] == T[p - i]) {
                p++;
            }
            next[i] = p - i;
            a = i;
        } else {
            next[i] = next[i - a];
        }
    }
}

/* 求解extend[] */
void GetExtend(string &S, int &n, string &T, int &m, int extend[], int next[]) {
    int a = 0, p = 0;
    GetNext(T, m, next);
    for (int i = 0; i < n; i++) {
        // i>=p 的作用：举个典型例子，S和T无一字符相同
        if (i >= p || i + next[i - a] >= p) {
            if (i >= p) {
                p = i;
            }
            while (p < n && p - i < m && S[p] == T[p - i]) {
                p++;
            }
            extend[i] = p - i;
            a = i;
        } else {
            extend[i] = next[i - a];
        }
    }
}

int main() {
    int next[100];
    int extend[100];
    string S, T;
    int n, m;
    while (cin >> S >> T) {
        n = S.size();
        m = T.size();
        GetExtend(S, n, T, m, extend, next);
        // print next
        cout << "next: ";
        for (int i = 0; i < m; i++) {
            cout << next[i] << " ";
        }
        // print extend
        cout << endl << "extend: ";
        for (int i = 0; i < n; i++) {
            cout << extend[i] << " ";
        }
        cout << endl << endl;
    }
    return 0;
}