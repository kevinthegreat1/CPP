//
// Created by Kevin Yang on 3/20/21.
//

#include <iostream>
#include <vector>

using namespace std;

int n;
vector<string> answer;

void dfs(int number, int total, string& parentheses) {
    if (total == n && number == 0) {
        answer.push_back(parentheses);
    }
    if (total < n) {
        parentheses.push_back('(');
        dfs(number + 1, total + 1, parentheses);
        parentheses.pop_back();
    }
    if (number > 0) {
        parentheses.push_back(')');
        dfs(number - 1, total, parentheses);
        parentheses.pop_back();
    }
}

int main() {
    cin >> n;
    string parentheses;
    dfs(0, 0, parentheses);
//    vector<string> t = answer;
    return 0;
}