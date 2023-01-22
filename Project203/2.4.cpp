//
// Created by Kevin Yang on 12/26/22.
//

#include <iostream>
#include <cstring>
#include <queue>
#include <unordered_set>

using namespace std;

int m;
int directions[4][2] = {{1,  0},
                        {1,  1},
                        {-1, -1},
                        {-1, 0}};

typedef struct Map {
    int map[6][6];
    int x0, y0;
    int step;
    size_t hash;

    Map() {
        memset(map, 0, sizeof(map));
        x0 = 0;
        y0 = 0;
        step = 0;
        hash = 0;
    }

    Map(const Map &map) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                this->map[i][j] = map.map[i][j];
            }
        }
        this->x0 = map.x0;
        this->y0 = map.y0;
        this->step = map.step;
        this->hash = map.hash;
    }

    void updateHash() {
        size_t tempHash = 0;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j <= i; j++) {
                tempHash = (tempHash << 3) | map[i][j];
            }
        }
        hash = tempHash;
    }
} Map;

struct Hash {
    size_t operator()(const Map &map) const {
        size_t hash = 0;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j <= i; j++) {
                hash = (hash << 3) | map.map[i][j];
            }
        }
        return hash;
    }
};

inline bool operator==(const Map &a, const Map &b) {
    return a.hash == b.hash;
}

queue<Map> q1, q2;
int steps;
unordered_set<Map, Hash> visited1, visited2;

void printMap(const Map &map) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j <= i; j++) {
            cout << map.map[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printQueue(queue<Map> q) {
    while (!q.empty()) {
        printMap(q.front());
        q.pop();
    }
}

void printVisited(const unordered_set<Map, Hash> &visited) {
    for (const Map &map: visited) {
        printMap(map);
    }
}

int bfs(queue<Map> &q, unordered_set<Map, Hash> &visited, const unordered_set<Map, Hash> &other) {
    Map cur = q.front();
    q.pop();
    for (int *direction: directions) {
        int nextX0 = cur.x0 + direction[0];
        int nextY0 = cur.y0 + direction[1];
        if (nextX0 >= 0 && nextX0 < 6 && nextY0 >= 0 && nextY0 <= nextX0) {
            Map next(cur);
            next.x0 = nextX0;
            next.y0 = nextY0;
            swap(next.map[cur.x0][cur.y0], next.map[nextX0][nextY0]);
            next.step++;
            next.updateHash();
            if (visited.find(next) == visited.end()) {
                visited.insert(next);
                q.push(next);
                auto match = other.find(next);
                if (match != other.end()) {
                    return next.step + match->step - 1;
                }
            }
        }
    }
    return -1;
}

void solve() {
    Map map1, map2;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> map1.map[i][j];
            if (map1.map[i][j] == 0) {
                map1.x0 = i;
                map1.y0 = j;
            }
            map2.map[i][j] = i;
        }
    }
    map1.step = map2.step = 0;
    map1.updateHash();
    map2.updateHash();
    q1.push(map1);
    q2.push(map2);
    while (q1.front().step < 10 || q2.front().step < 10) {
        if (q1.front().step < 10 && (steps = bfs(q1, visited1, visited2)) >= 0) {
            cout << steps << endl;
            return;
        }
        if (q2.front().step < 10 && (steps = bfs(q2, visited2, visited1)) >= 0) {
            cout << steps << endl;
            return;
        }
    }
}

int main() {
    cin >> m;
    for (int i = 0; i < m; i++) {
        solve();
    }
    return 0;
}