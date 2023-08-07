/*
Q2: 有n+1个点编号为0~n，其中1~n的点上有价值为p[i]的物品，给出m条边和每条边的距离，从0出发到1~n这n个点中的x个点的距离和最小、且x个点的价值之和必须超过总的价值之和的一半
(1<=n<=100, 1<=m<=10000, 0<=dis<=100, 0<=p[i]<=100)

Input:
2 3 (n,m)
0 2 9  (s->t, dis)
2 1 3
1 0 2
1 3 (p[i])
Output:
5
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 101;
const int P = 5001;

typedef struct Edge {
    int from;
    int to;
    int cost;
    int totalCost;

    explicit Edge(int from = 0, int to = 0, int cost = 0, int totalCost = 0) : from(from), to(to), cost(cost),
                                                                               totalCost(totalCost) {}

    bool operator<(Edge other) const {
        return totalCost > other.totalCost || (totalCost == other.totalCost && cost > other.cost) ||
               (totalCost == other.totalCost && cost == other.cost && from > other.from) ||
               (totalCost == other.totalCost && cost == other.cost && from == other.from && to > other.to);
    }
} Edge;

void spfa(int n, int totalCosts[], vector<Edge> edges[]) {
    priority_queue<Edge> curEdges;
    int count = 1;
    memset(totalCosts, -1, sizeof(*totalCosts) * n);
    curEdges.emplace();
    while (!curEdges.empty()) {
        Edge curEdge = curEdges.top();
        curEdges.pop();
        if (totalCosts[curEdge.to] >= 0) {
            continue;
        }
        for (Edge edge: edges[curEdge.to]) {
            if (totalCosts[edge.to] < 0) {
                edge.totalCost = curEdge.totalCost + edge.cost;
                curEdges.push(edge);
            }
        }
        totalCosts[curEdge.to] = curEdge.totalCost;
        if (count++ == n) {
            break;
        }
    }
}

int dp(int n, int targetValue, int costs[], int values[]) {
    int dp[N][P];
    for (int j = 1; j <= targetValue; j++) {
        dp[0][j] = P * 2;
    }
    for (int i = 1; i <= n; i++) {
        dp[i][0] = 0;
        for (int j = 1; j <= targetValue; j++) {
            if (j - values[i] >= 0) {
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - values[i]] + costs[i]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][targetValue];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges[n + 1];
    for (int i = 0; i < m; i++) {
        int from, to, distance;
        cin >> from >> to >> distance;
        if (from > to) { swap(from, to); }
        edges[from].emplace_back(from, to, distance, distance);
    }
    int totalDistances[N];
    spfa(n + 1, totalDistances, edges);
    int values[n + 1];
    int totalValue = 0;
    for (int i = 1; i <= n; i++) {
        cin >> values[i];
        totalValue += values[i];
    }
    cout << dp(n, totalValue / 2 + 1, totalDistances, values);
    return 0;
}
