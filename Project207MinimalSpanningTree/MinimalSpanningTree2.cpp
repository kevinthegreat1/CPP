//
// Created by Kevin Yang on 1/13/23.
//

#include <iostream>
#include <set>

using namespace std;

const int N = 100001;
int nBuildings, mPipes, d;

typedef struct Edge {
    int from;
    int to;
    int cost;
    bool active;

    bool operator<(Edge b) const {
        return cost < b.cost || (cost == b.cost && active) || (cost == b.cost && active == b.active && from < b.from) ||
               (cost == b.cost && active == b.active && from == b.from && to < b.to);
    }
} Edge;

typedef struct UnionFind {
private:
    int unionFind[N];
    int setCount;
public:

    void init(int count) {
        for (int i = 0; i < count; i++) {
            unionFind[i] = i;
        }
        setCount = count;
    }

    int getCount() const {
        return setCount;
    }

    int find(int a) {
        if (unionFind[a] == a) {
            return a;
        }
        return unionFind[a] = find(unionFind[a]);
    }

    bool isSameSet(int a, int b) {
        return find(a) == find(b);
    }

    void Union(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        unionFind[rootA] = rootB;
        setCount--;
    }
} UnionFind;

Edge largestEdgeInMst;
int inactiveCount;

set<Edge> getMinimalSpanningTree(set<Edge> &edges) {
    UnionFind uf;
    uf.init(nBuildings);
    set<Edge> res;
    inactiveCount = 0;
    for (Edge edge: edges) {
        if (!uf.isSameSet(edge.from, edge.to)) {
            uf.Union(edge.from, edge.to);
            res.insert(edge);
            if (!edge.active) {
                inactiveCount++;
            }
        }
        if (uf.getCount() == 1) {
            largestEdgeInMst = edge;
            break;
        }
    }
    return res;
}

int main() {
    cin >> nBuildings >> mPipes >> d;
    set<Edge> allEdges;
    set<Edge> activeEdges;
    for (int i = 0; i < mPipes; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        Edge edge = {from, to, cost, i < nBuildings - 1};
        allEdges.insert(edge);
        if (edge.active) {
            activeEdges.insert(edge);
        }
    }
    set<Edge> mst = getMinimalSpanningTree(allEdges);
    if (largestEdgeInMst.cost < d) {
        mst.erase(largestEdgeInMst);
        mst.insert(activeEdges.begin(), activeEdges.upper_bound({0, 0, d, true}));
        mst = getMinimalSpanningTree(mst);
    }
    cout << inactiveCount << endl;
    return 0;
}