//
// Created by kyang25 on 8/14/23.
//

/*
有一个N*N的网格，有K个障碍物，你有一个超能力，每次使用超能力可以清除该网格特定行或者列的所有障碍物，问最少需要多少次超能力才能清除掉所有障碍物。
N<=500, 障碍物数量<=10000

3
X.X
.X.
.X.

XXXXXXXX
..X..X..
..X..X..
..X..X..
..X..X..
..X..X..
..X..X..
..X..X..

0~(n-1)行为N个点
0~(n-1)列为另外N个点
(i,j)的位置有一个障碍物，将行的第i个点和列的第j个点连一条边
选择最少的点使得所有的边都至少有一个端点被选中
（最小覆盖=最大匹配，霍尔定理Hall）

匈牙利算法：
二分图：无向图中点集可以被划分为两部分，每个部分内部没有边、两个部分之间有无向边
交替路/增广路：从一个没有匹配的节点出发，经过一个没有被选中的边、经过一个已有匹配的边、经过一个没有被选中的边、经过一个已有匹配的边、……、经过一个没有被选中的边
将已有匹配和增广路进行异或，可以得到匹配数+1的新匹配
*/

#include <iostream>

using namespace std;

const int N = 500;

typedef struct Edge {
    int from;
    int to;

    Edge(int from, int to) : from(from), to(to) {};
} Edge;

vector<Edge> edges[N];
int pairs[N];
bool visited[N];

bool hungary(const int &cur) {
    if (visited[cur]) {
        return false;
    }
    visited[cur] = true;
    for (Edge edge: edges[cur]) {
        if (pairs[edge.to] < 0) {
            pairs[edge.to] = edge.from;
            return true;
        } else {
            if (hungary(pairs[edge.to])) {
                pairs[edge.to] = edge.from;
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    char grid[N][N];
    memset(pairs, -1, sizeof(pairs));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'X') {
                edges[i].emplace_back(i, j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        memset(visited, 0, sizeof(visited));
        hungary(i);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (pairs[i] >= 0) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}