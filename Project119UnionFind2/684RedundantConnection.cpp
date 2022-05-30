//
// Created by Kevin Yang on 7/29/21.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        UnionFind unionFind = UnionFind(2 * edges.size());
        vector<int> redundant;
        for (vector<int> &edge:edges) {
            if (unionFind.isConnected(edge[0], edge[1])) {
                redundant = edge;
                continue;
            }
            unionFind.Union(edge[0], edge[1]);
        }
        return redundant;
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
            parent[rootA] = rootB;
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
}