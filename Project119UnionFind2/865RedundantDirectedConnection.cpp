//
// Created by Kevin Yang on 7/29/21.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges) {
        int n = edges.size(), collision = -1, loop = -1, i;
        UnionFind unionFind = UnionFind(n + 1);
        vector<int> parents(n + 1);
        for (i = 0; i <= n; i++) {
            parents[i] = i;
        }
        for (i = 0; i < n; i++) {
            if (parents[edges[i][1]] != edges[i][1]) {
                collision = i;
                continue;
            }
            parents[edges[i][1]] = edges[i][0];
            if (unionFind.isConnected(edges[i][0], edges[i][1])) {
                loop = i;
                continue;
            }
            unionFind.Union(edges[i][0], edges[i][1]);
        }
        if (collision >= 0) {
            if (loop >= 0) {
                return vector<int>{parents[edges[collision][1]], edges[collision][1]};
            } else {
                return vector<int>{edges[collision][0], edges[collision][1]};
            }
        }
        return vector<int>{edges[loop][0], edges[loop][1]};
    }

private:
    class UnionFind {
        vector<int> parent;

    public:
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
};

int main() {
    Solution solution;
    vector<vector<int>> edges = {{2,1},{3,1},{4,2},{1,4}};
//    vector<vector<int>> edges = {{4,2},{1,5},{5,2},{5,3},{2,4}};
    vector<int> redundant = solution.findRedundantDirectedConnection(edges);
    cout << redundant[0] << ", " << redundant[1];
}