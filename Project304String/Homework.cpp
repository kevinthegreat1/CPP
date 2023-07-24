/*
 * Q1:
 *      给定字符串S(length<1E6)，它是由另一个字符串X重复若干次得到的，至少两次，次数可能不是整数，问X最短是多长？
 *      S=cabcabcabcab
 *      X=cab
 * 
 * Q2:
 *      给定字符串S，如果对于S的长度为i的前缀是“循环同构”的（由某个字符串X重复至少两次得到），求i和重复次数c
 *      S=aaa
 *      i=[2,3]
 *      c=[2,3]
 * 
 *      S=aabaabaabaab
 *      i=[2,6,9,12]
 *      c=[2,2,3,4]
 * 
 * Q3:
 *      给定一个字符串S，如果S的一个不等于S的前缀X满足：S是X+X的前缀，就把X叫做S的一个“周期串”，求所有前缀的最大周期串长度之和
 *      S=babababa
 *      prefix: b: none
 *              ba: none
 *              bab: ba 2
 *              baba: ba 2
 *              babab: baba 4
 *              bababa: baba 4
 *              bababab: baba, bababa, max(4,6)=6
 *              babababa: baba, bababa, max(4,6)=6
 *      ans=24
 */

#include <iostream>
#include <string>

using namespace std;

typedef struct UnionFind {
private:
    int setCount;
public:
    static int find(int unionFind[], int a) {
        if (unionFind[a] == a || unionFind[a] == 0) {
            return a;
        }
        return unionFind[a] = find(unionFind, unionFind[a]);
    }

    static bool isSameSet(int unionFind[], int a, int b) {
        return find(unionFind, a) == find(unionFind, b);
    }
} UnionFind;

void kmp_nxt(const string &target, int next[]) {
    int j = next[0] = -1;
    for (int i = 0; i < target.length();) {
        if (j < 0 || target[j] == target[i]) next[++i] = ++j;
        else j = next[j];
    }
}

vector<int> kmp(const string &s, const string &target, const int next[], const int &sLen, const int &targetLen) {
    vector<int> ans;
    int j = 0;
    for (int i = 0; i < sLen;) {
        if (j < 0 || s[j] == target[i]) {
            i++;
            j++;
            if (j >= targetLen) {
                //matched
                ans.push_back(i - targetLen + 1);
                j = next[j];
            }
        } else j = next[j];
    }
    return ans;
}


// go forward until the char in s is same as first char in s
// then set sub and start match
// if it does not match go back to the last place where the char equals the first char is checked
// wait until the next char same as beginning char
int shortestRepeatingSubstring(const string &s) {
    string sub;
    int j = 0;
    for (int i = 0; i < s.length(); i++) {
        if (sub.empty() && s[i] == s[0]) { // char in s equals first char in s, potential repeat
            sub = s.substr(0, i);
            j = 1;
        } else if (!sub.empty() && s[i] != sub[j]) { // if does not match
            i = sub.length(); // go back to last place where the char in s was checked
            sub = "";
        } else {
            j = (j + 1) % (int) sub.length(); // if matches, continue matching until end
        }
    }
    return sub.length();
}

vector<pair<int, int>> repeatedFrontIn(const string &s) {
    // i % (i-next[i]) == 0
    // i / (i-next[i]) >= 2
}

vector<int> longestRepeatingSubstring(const string &s) {
    int next[s.length()];
    kmp_nxt(s, next);
    vector<int> ans;
    for (int i = 1; i <= s.length(); i++) {
        int j = i;
        if (next[j] == 0) {
            ans.push_back(0);
            continue; // none exists
        }
        ans.push_back(i - UnionFind::find(next, next[j]));
    }
    return ans;
}

int main() {
    string s;
    cin >> s;
    vector<int> ans = longestRepeatingSubstring(s);
    for (int sub: ans) {
        cout << sub << ", ";
    }
    cout << endl;
    return 0;
};