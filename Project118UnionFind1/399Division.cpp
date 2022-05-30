//
// Created by Kevin Yang on 7/24/21.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<double>
    calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries) {
        int n = equations.size(), id = 0, i;
        UnionFind unionFind = UnionFind(2 * n);
        map<string, int> variables;
        for (i = 0; i < n; i++) {
            vector<string> equation = equations[i];
            string var1 = equation[0];
            string var2 = equation[1];
            if (variables.find(var1) == variables.end()) {
                variables.insert(pair<string, int>(var1, id));
                id++;
            }
            if (variables.find(var2) == variables.end()) {
                variables.insert(pair<string, int>(var2, id));
                id++;
            }
            unionFind.Union(variables.at(var1), variables.at(var2), values[i]);
        }

        vector<double> result;
        for (vector<string> &query:queries) {
            if (variables.find(query[0]) == variables.end() || variables.find(query[1]) == variables.end()) {
                result.push_back(-1);
                continue;
            }
            if (query[0] == query[1]) {
                result.push_back(1);
                continue;
            }
            if (variables.find(query[0]) == variables.end() || variables.find(query[1]) == variables.end()) {
                result.push_back(-1);
            } else {
                result.push_back(unionFind.isConnected(variables.at(query[0]), variables.at(query[1])));
            }
        }
        return result;
    }

private:
    class UnionFind {
        vector<int> parent;
        vector<double> weight;

    public:
        explicit UnionFind(int n) {
            for (int i = 0; i < n; i++) {
                parent.push_back(i);
                weight.push_back(1);
            }
        }

        void Union(int a, int b, double value) {
            int rootA = find(a);
            int rootB = find(b);
            if (rootA == rootB) {
                return;
            }
            parent[rootA] = rootB;
            weight[rootA] = weight[b] * value / weight[a];
        }

        int find(int a) {
            if (a != parent[a]) {
                int t=parent[a];
                parent[a]=find(parent[a]);
                weight[a]*=weight[t];
            }
            return parent[a];
        }

        double isConnected(int a, int b) {
            if (find(a) == find(b)) {
                return weight[a] / weight[b];
            } else {
                return -1;
            }
        }
    };
};

int main() {
    Solution solution;
    vector<vector<string>> equations = {{"x1","x2"},{"x2","x3"},{"x3","x4"},{"x4","x5"}};
    vector<double> values = {3, 4, 5, 6};
    vector<vector<string>> queries = {{"x1","x5"},{"x5","x2"},{"x2","x4"},{"x2","x2"},{"x2","x9"},{"x9","x9"}};
    vector<double> results = solution.calcEquation(equations, values, queries);
    for (double result:results) {
        cout << result << ", ";
    }
    return 0;
}