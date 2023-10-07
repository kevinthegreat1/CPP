//
// Created by kyang25 on 10/6/23.
//

// Luogu P4391

#include <iostream>

using namespace std;

void kmpNext(string s, int next[], int num[]) {
    int j = next[0] = -1;
    num[0] = -1;
    for (int i = 0; i < s.length();) {
        while (j >= 0 && s[i] != s[j]) {
            j = next[j];
        }
        next[++i] = ++j;
        num[i] = num[j] + 1;
    }
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int next[s.length() + 1], num[s.length() + 1];
    kmpNext(s, next, num);
    cout << n - next[n];
}