//
// Created by Kevin Yang on 3/14/21.
//

#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int> > tree;

void put(vector<int> path) {
    int i, j;
    if (path.size() == n) {
        return;
    }
    vector<int> t;
    for (i = 1; i <= n; i++) {
        for (j = 0; j < path.size(); j++) {
            if (i == path[j]) {
                break;
            } else if (j == path.size() - 1) {
                tree[path.size()].push_back(i);
                t=path;
                t.push_back(i);
                put(t);
                t.clear();
            }
        }
    }
}

int main(){
    int i, j, t1;
    vector<int> path, t2;
    cin>>n;
    tree.resize(n);
    for (i = 0; i < n; ++i) {
        cin>>t1;
        tree[0].push_back(t1);
        path.push_back(t1);
        put(path);
        path.clear();
    }
    vector<vector<int>> a=tree;
    return 0;
}