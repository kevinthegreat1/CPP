//
// Created by Kevin Yang on 5/1/21.
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
        queue<string> queue;
        set<string> deads, visited;
        for(string dead:deadends) deads.insert(dead);
        queue.push("0000");
        visited.insert("0000");
        while (!queue.empty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                string cur = queue.front();
                queue.pop();
                if (cur == target) {
                    return depth;
                }
                for (int j = 0; j < 4; j++) {
                    string s1 = cur + j;
                    string s2 = cur - j;
                    if (visited.find(s1) == visited.end() && deads.find(s1) == deads.end()) {
                        queue.push(s1);
                    }
                    if (visited.find(s2) == visited.end() && deads.find(s2) == deads.end()) {
                        queue.push(s2);
                    }
                }
            }
            depth++;
        }
        return -1;
    }
};

int main(){
    Solution solution;
    vector<string> s{"8888"};
    solution.openLock(s,"0009");
}