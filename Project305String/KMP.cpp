/*
Q4: 给定字符串S(length<1E6)，求一个num数组，num[i]表示S的长度为i的前缀P满足：(既是P的前缀又是P的后缀且长度<=i/2的)子串的个数
求(num[i]+1)从i=1~S.length的累乘，对1E9+7取模

S:   aaaaa
num: 01122(a,aa)
ans: 36

S:   ab
num: 00
ans: 1

S:   abcababc
num: 00011111
ans: 32

*/

#include <iostream>
#include <vector>

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

int prefixAndSuffix(const string &s) {
    int next[s.length() + 1], num[s.length() + 1];
    kmpNext(s, next, num);
    int ans = 1;
    for (int i = 1; i <= s.length(); i++) {
        int j = i;
        while (next[j] > i / 2) {
            j = next[j];
        }
        if (j > 0) {
            ans *= num[j] + 1;
        }
    }
    return ans;
}

int main() {
    string s;
    cin >> s;
    cout << prefixAndSuffix(s) << endl;
    return 0;
}