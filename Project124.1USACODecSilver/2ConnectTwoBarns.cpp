//
// Created by Kevin Yang on 12/19/21.
//

#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
public:
    vector<int> parent;

    explicit UnionFind(int n) {
        for (int i = 0; i < n; i++) {
            parent.push_back(i);
        }
    }

    void Union(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA == rootB) {
            return;
        }
        parent[rootB] = rootA;
    }

    int find(int a) {
        if (a != parent[a]) {
            parent[a] = find(parent[a]);
        }
        return parent[a];
    }

    bool isConnected(int a, int b) {
        return find(a) == find(b);
    }
};

long long closest(vector<int> a, vector<int> b){
    long long diff = INT64_MAX, l = 0, r = 0;
    while (l < a.size() && r < b.size()) {
        diff = min((long long)abs(a[l] - b[r]), diff);
        if (a[l] - b[r] > 0) {
            r++;
        } else {
            l++;
        }
    }
    return diff;
}

int main() {
    int t, n, m, i, j;
    cin >> t;
    for (i = 0; i < t; i++) {
        cin >> n >> m;
        UnionFind unionFind = UnionFind(n + 1);
        for (j = 0; j < m; j++) {
            int t1, t2;
            cin >> t1 >> t2;
            unionFind.Union(t1, t2);
        }
        for (j = 1; j <= n; j++) {
            unionFind.find(j);
        }
        if (unionFind.isConnected(1, n)) {
            cout << 0 << endl;
            continue;
        }
        vector<int> barn1, barn2;
        vector<vector<int>> connected(n + 1);
        for (j = 1; j <= n; j++) {
            if (unionFind.parent[j] == unionFind.parent[1]) {
                barn1.push_back(j);
            } else if (unionFind.parent[j] == unionFind.parent[n]) {
                barn2.push_back(j);
            } else {
                connected[unionFind.parent[j]].push_back(j);
            }
        }
        long long cost = closest(barn1, barn2);
        if (cost % 2) {
            --cost /= 2;
            cost = cost * cost + (cost + 1) * (cost + 1);
        } else {
            cost /= 2;
            cost = cost * cost * 2;
        }
        if (cost == 1) {
            cout << cost << endl;
            continue;
        }
        for (j = 1; j <= n; j++) {
            if (connected[j].empty()) {
                continue;
            }
            long long t1 = closest(barn1, connected[j]), t2 = closest(connected[j], barn2);
            cost = min(t1 * t1 + t2 * t2, cost);
        }
        cout << cost << endl;
    }
    return 0;
}