//
// Created by Kevin Yang on 1/13/23.
//

#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <queue>

using namespace std;

const int N = 100001;
int nPlanets, mCities, qUniqueFlights, qUniquePortals, totalCities;

typedef struct Edge {
    bool type;
    int from;
    int to;
    int cost;

    bool operator<(Edge b) const {
        return cost < b.cost;
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

set<Edge> flights, portals;
UnionFind citiesUF, planetsUF;

void printEdge(const string &text, Edge edge) {
    cout << text << " Type: " << (!edge.type ? "Flight" : "Portal") << " To: " << edge.to << " Cost: " << edge.cost
         << endl;
}

int useEdgeAndCalculateCost(Edge edge) {
    if (!edge.type) {
        citiesUF.Union(edge.from, edge.to);
        return edge.cost * planetsUF.getCount();
    } else {
        planetsUF.Union(edge.from, edge.to);
        return edge.cost * citiesUF.getCount();
    }
}

int solve() {
    int cost = 0;
    auto leastExpensiveFlight = flights.begin();
    auto leastExpensivePortal = portals.begin();
    citiesUF.init(mCities);
    planetsUF.init(nPlanets);
    while (citiesUF.getCount() > 1 || planetsUF.getCount() > 1) {
//        printEdge("Current lease expensive flight: ", *leastExpensiveFlight);
//        printEdge("Current lease expensive portal: ", *leastExpensivePortal);
//        cout << "Current cost: " << cost << endl;
//        cout << "Current city sets count: " << citiesUF.getCount() << endl;
//        cout << "Current planet sets count: " << planetsUF.getCount() << endl;
        // Use the least expensive flight if it is cheaper than the least expensive portal or no portals are needed.
        if ((leastExpensiveFlight->cost <= leastExpensivePortal->cost || planetsUF.getCount() == 1) &&
            citiesUF.getCount() > 1 &&
            !citiesUF.isSameSet(leastExpensiveFlight->from, leastExpensiveFlight->to)) {
//            printEdge("Using flight: ", *leastExpensiveFlight);
            cost += useEdgeAndCalculateCost(*leastExpensiveFlight);
            if (++leastExpensiveFlight == flights.end()) {
                leastExpensiveFlight--;
            }
        }
            // Use the least expensive portal if it is cheaper than the least expensive flight or no flights are needed.
        else if ((leastExpensivePortal->cost <= leastExpensiveFlight->cost || citiesUF.getCount() == 1) &&
                 planetsUF.getCount() > 1 &&
                 !planetsUF.isSameSet(leastExpensivePortal->from, leastExpensivePortal->to)) {
//            printEdge("Using portal: ", *leastExpensivePortal);
            cost += useEdgeAndCalculateCost(*leastExpensivePortal);
            if (++leastExpensivePortal == portals.end()) {
                leastExpensivePortal--;
            }
        }
    }
    return cost;
}

int main() {
    cin >> nPlanets >> mCities >> qUniqueFlights >> qUniquePortals;
    totalCities = nPlanets * mCities;
    int totalCost = 0;
    for (int i = 0; i < qUniqueFlights; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        flights.insert({0, a, b, c});
        totalCost += c * nPlanets;
    }
    for (int i = 0; i < qUniquePortals; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        portals.insert({1, a, b, c});
        totalCost += c * mCities;
    }
    int cost = solve();
//    cout << "Calculated cost: " << cost << endl;
//    cout << "Total cost: " << totalCost << endl;
    cout << totalCost - cost << endl;
    return 0;
}