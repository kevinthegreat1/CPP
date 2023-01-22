//
// Created by Kevin Yang on 1/8/23.
//

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

const int N = 1001;
int n;

typedef struct Edge {
    int to;
    int cost;

    bool operator<(Edge b) const {
        return cost > b.cost;
    }
} Edge;

vector<Edge> edges[N];
map<pair<int, int>, pair<int, int>> penEdges;

int getMinimalSpanningTree(int pens) {
    priority_queue<Edge> curEdges;
    set<int> visited;
    curEdges.push({1, 0});
    int totalCost = 0;
    while (!curEdges.empty()) {
        Edge curEdge = curEdges.top();
        curEdges.pop();
        if (visited.find(curEdge.to) != visited.end()) {
            continue;
        }
        for (Edge newEdge: edges[curEdge.to]) {
            if (visited.find(newEdge.to) == visited.end()) {
                curEdges.push(newEdge);
            }
        }
        visited.insert(curEdge.to);
        totalCost += curEdge.cost;
    }

    return visited.size() == pens ? totalCost : INT32_MAX;
}

int main() {
    cin >> n;
    int corners[N];
    for (int i = 1; i <= n; i++) {
        int sides;
        cin >> sides;
        for (int j = 0; j < sides; j++) {
            cin >> corners[j];
        }
        for (int j = 0; j < sides; j++) {
            int cost;
            cin >> cost;
            int corner1 = corners[j];
            int corner2 = corners[(j + 1) % sides];
            if (corner1 > corner2) {
                swap(corner1, corner2);
            }
            auto pen2It = penEdges.find({corner1, corner2});
            if (pen2It != penEdges.end()) {
                int pen2 = pen2It->second.first;
                edges[i].push_back({pen2, cost});
                edges[pen2].push_back({i, cost});
                penEdges.erase(pen2It);
            } else {
                penEdges.insert({{corner1, corner2},
                                 {i,       cost}});
            }
        }
    }

    int totalCostWithoutOutside = getMinimalSpanningTree(n);

    for (auto penEdge: penEdges) {
        int pen1 = 0;
        int pen2 = penEdge.second.first;
        int cost = penEdge.second.second;
        edges[pen1].push_back({pen2, cost});
        edges[pen2].push_back({pen1, cost});
    }

    int totalCostWithOutside = getMinimalSpanningTree(n + 1);

    cout << min(totalCostWithoutOutside, totalCostWithOutside) << endl;
    return 0;
}