//
// Created by Kevin Yang on 1/13/23.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int N = 100001;
int n, m, p, q, cities;

typedef struct City {
    int planet;
    int city;
} City;

typedef struct Edge {
    City to;
    int cost;

    bool operator<(Edge b) const {
        return cost > b.cost;
    }
} Edge;

vector<Edge> flights[N], portals[N];

void printEdge(const string &text, Edge edge) {
    cout << text << edge.to.planet << " " << edge.to.city << " " << edge.cost << endl;
}

int getMinimalSpanningTree() {
    priority_queue<Edge> curEdges;
    int visitedCount = 0;
    memset(visited, 0, sizeof(visited));
    curEdges.push({{1, 1}, 0});
    int totalCost = 0;
    while (!curEdges.empty()) {
        printEdge("Current edge: ", curEdges.top());
        Edge curEdge = curEdges.top();
        curEdges.pop();
        if (visited[curEdge.to.planet][curEdge.to.city]) {
            continue;
        }
        for (Edge flight: flights[curEdge.to.city]) {
            flight.to.planet = curEdge.to.planet;
            if (!visited[flight.to.planet][flight.to.city]) {
                curEdges.push(flight);
                printEdge("Pushed flight: ", flight);
            }
        }
        for (Edge portal: portals[curEdge.to.planet]) {
            portal.to.city = curEdge.to.city;
            if (!visited[portal.to.planet][portal.to.city]) {
                curEdges.push(portal);
                printEdge("Pushed portal: ", portal);
            }
        }
        visited[curEdge.to.planet][curEdge.to.city] = true;
        totalCost += curEdge.cost;
        cout << "Visited cities: " << visitedCount + 1 << endl;
        cout << "Total cities: " << cities << endl;
        if (++visitedCount == cities) {
            return totalCost;
        }
    }
    return INT32_MAX;
}

int main() {
    cin >> n >> m >> p >> q;
    cities = n * m;
    int totalCost = 0;
    for (int i = 0; i < p; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        flights[a].push_back({{0, b}, c});
        flights[b].push_back({{0, a}, c});
        totalCost += c * n;
    }
    for (int i = 0; i < q; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        portals[a].push_back({{b, 0}, c});
        portals[b].push_back({{a, 0}, c});
        totalCost += c * m;
    }
    cout << getMinimalSpanningTree() << endl;
    cout << "Total cost: " << totalCost << endl;
    return 0;
}