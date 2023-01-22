//
// Created by Kevin Yang on 1/13/23.
//

#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <queue>

using namespace std;

const int N = 100001;
int n, m, d;

typedef struct Edge {
    int to;
    int cost;
    bool active;

    bool operator<(Edge b) const {
        return cost > b.cost || (cost == b.cost && !active);
    }
} Edge;

vector<Edge> allEdges;
vector<Edge> edges[N];

int getMinimalSpanningTree() {
    priority_queue<Edge> curEdges;
    bool visited[N];
    int count = 1;
    memset(visited, 0, sizeof(visited));
    int maxEdgeCost = 0;
    curEdges.push({0, 0, true});
    visited[0] = true;
    while (!curEdges.empty()) {
        Edge curEdge = curEdges.top();
        curEdges.pop();
        if (visited[curEdge.to]) {
            continue;
        }
        for (Edge edge: edges[curEdge.to]) {
            if (!visited[edge.to]) {
                curEdges.push(edge);
            }
        }
        visited[curEdge.to] = true;
        maxEdgeCost = max(curEdge.cost, maxEdgeCost);
        if (++count == n) {
            return maxEdgeCost;
        }
    }
    return INT32_MAX;
}

int getMinimalSpanningTreeByEdgeLength(){

}

int main() {
    cin >> n >> m >> d;
    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        Edge edge = {to, cost, i < n - 1};
        edges[from].push_back(edge);
        allEdges.push_back(edge);
    }
    int maxEdgeCost = getMinimalSpanningTree();
    return 0;
}