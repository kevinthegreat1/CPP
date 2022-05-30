//
// Created by Kevin Yang on 5/8/21.
//

#include <iostream>
#include <queue>
#include <set>

using namespace std;

string operator + (string s, int j){
    if(s[j]=='9'){
        s[j]='0';
    } else {
        s[j]+=1;
    }
    return s;
}

string operator - (string s, int j){
    if(s[j]=='0'){
        s[j]='9';
    } else {
        s[j]-=1;
    }
    return s;
}

class Solution {
public:
    int openLock(vector<string> &deadends, string target) {
        int depth = 0;
        set<string> q1, q2, deads, visited;
        for(string dead:deadends) deads.insert(dead);
        q1.insert("0000");
        q2.insert(target);
        visited.insert("0000");
        while (!q1.empty() && !q2.empty()) {
            set<string> t;
            for (const string &cur : q1) {
                if (deads.find(cur) != deads.end()) {
                    continue;
                }
                if (q2.find(cur)!=q2.end()) {
                    return depth;
                }
                visited.insert(cur);
                for (int j = 0; j < 4; j++) {
                    string s = cur + j;

                    if (visited.find(s) == visited.end()) {
                        t.insert(s);
                    }
                    s = cur - j;
                    if (visited.find(s) == visited.end()) {
                        t.insert(s);
                    }
                }
            }
            depth++;
            q1 = q2;
            q2 = t;
        }
        return -1;
    }
};

int main(){
    Solution solution;
    vector<string> s{"0201","0101","0102","1212","2002"};
    cout<<solution.openLock(s,"0202");
    return 0;
}

//Leetcode 752