//
// Created by Kevin Yang on 12/23/22.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int N = 100001;

typedef struct Edge {
    int to;
    int cost;

    explicit Edge(int to = 0, int cost = 0) : to(to), cost(cost) {}
} Edge;
vector<Edge> edges[N];
int n, m;

void addEdge(int from, int to, int cost) {
    edges[from].emplace_back(to, cost);
}

queue<int> q;
bool inQueue[N];
int cnt[N];
int dis[N];

bool spfa(int s) {
    for (int i = 0; i < n; i++) {
        cnt[i] = 0;
        dis[i] = INT32_MAX;
        inQueue[i] = false;
    }
    q.push(s);
    cnt[s] = 1;
    dis[s] = 0;
    inQueue[s] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        inQueue[cur] = false;
        for (Edge edge: edges[cur]) {
            int next = edge.to;
            int newDis = dis[cur] + edge.cost;
            if (dis[next] > newDis) {
                dis[next] = newDis;
                if (!inQueue[next]) {
                    q.push(next);
                    inQueue[next] = true;
                    if (++cnt[next] > n) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        addEdge(from, to, cost);
    }
    int s, t;
    cin >> s >> t;
    cout << (spfa(s) ? dis[t] : INT64_MIN) << endl;
    return 0;
}