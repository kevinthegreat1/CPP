//
// Created by Kevin Yang on 12/30/22.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 10001, K = 201;
int k, n, m, start, target;

typedef struct State {
    int island;
    int thickness;
} State;

typedef struct Edge {
    int end;
    int time;
    int thickness;

    Edge(int end, int time, int thickness) : end(end), time(time), thickness(thickness) {}
} Edge;

vector<Edge> edges[N];
queue<State> q;
int timeToIs[N][K];
int cnt[N][K];
bool inQueue[N][K];
int ans = INT32_MAX;

int main() {
    cin >> k >> n >> m;
    for (int i = 0; i < m; i++) {
        int is1, is2, time, thickness;
        cin >> is1 >> is2 >> time >> thickness;
        edges[is1].emplace_back(is2, time, thickness);
        edges[is2].emplace_back(is1, time, thickness);
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            timeToIs[i][j] = INT32_MAX;
            cnt[i][j] = 0;
            inQueue[i][j] = false;
        }
    }
    cin >> start >> target;
    q.push({start, k});
    timeToIs[start][k] = 0;
    cnt[start][k] = 1;
    while (!q.empty()) {
        State cur = q.front();
        q.pop();
        if (cur.island == target) {
            ans = min(ans, timeToIs[cur.island][cur.thickness]);
        }
        inQueue[cur.island][cur.thickness] = false;
        for (Edge edge: edges[cur.island]) {
            int next = edge.end;
            int newTime = timeToIs[cur.island][cur.thickness] + edge.time;
            int newThickness = cur.thickness - edge.thickness;
            if (newThickness > 0 && newTime < timeToIs[next][newThickness]) {
                timeToIs[next][newThickness] = newTime;
                if (!inQueue[next][newThickness]) {
                    q.push({next, newThickness});
                    inQueue[next][newThickness] = true;
                    if (++cnt[next][newThickness] > n) {
                        cout << -1 << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << (ans == INT32_MAX ? -1 : ans) << endl;
    return 0;
}