//
// Created by Kevin Yang on 12/21/22.
//

#include <iostream>
#include <queue>

using namespace std;

const int N = 101;
char map[N][N];
int n;

typedef struct Point {
    int map;
    int x;
    int y;

    Point operator+(Point p) {
        return {map, x + p.x, y + p.y};
    }
} Point;

const Point directions[4] = {{0, 1,  0},
                             {0, -1, 0},
                             {0, 0,  1},
                             {0, 0,  -1}};
Point start;
Point target;
vector<Point> portals;
pair<Point, Point> doors[6];
Point teleport[N][N];

queue<Point> q;
bool visited[N][N];
int dis[N][N];

int getDirectionIndex(char direction) {
    switch (direction) {
        case 'D':
            return 0;
        case 'U':
            return 1;
        case 'R':
            return 2;
        case 'L':
            return 3;
        default:
            return -1;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            switch (map[i][j]) {
                case 'S':
                    start = {0, i, j};
                    break;
                case 'T':
                    target = {0, i, j};
                    break;
                case 'X':
                    portals.push_back({0, i, j});
                    break;
            }
            if (map[i][j] >= 'A' && map[i][j] <= 'F') {
                doors[map[i][j] - 'A'].second = {0, i, j};
            } else if (map[i][j] >= 'a' && map[i][j] <= 'f') {
                doors[map[i][j] - 'a'].second = {0, i, j};
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            teleport[i][j] = {-1, -1, -1};
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (getDirectionIndex(map[i][j]) != -1 && teleport[i][j].x == -1) {
                Point point = {0, i, j};
                vector<Point> passThrough;
                while (true) {
                    passThrough.push_back({point.map, point.x, point.y});
                    point = point + directions[getDirectionIndex(map[point.x][point.y])];
                    if (point.x < 0 || point.x >= n || point.y < 0 || point.y >= n || map[point.x][point.y] == '#') {
                        point = {-2, -2, -2};
                        break;
                    }
                    if (getDirectionIndex(map[point.x][point.y]) == -1) {
                        break;
                    }
                }
                for (Point point1: passThrough) {
                    teleport[point1.x][point1.y] = point;
                }
            }
        }
    }
    q.push(start);
    while (!q.empty()) {
        Point cur = q.front();
        q.pop();
        if (cur.x == target.x && cur.y == target.y) {
            break;
        }
        vector<int> allowed;
        if (map[cur.x][cur.y] != '-') {
            allowed.push_back(0);
            allowed.push_back(1);
        }
        if (map[cur.x][cur.y] != '|') {
            allowed.push_back(2);
            allowed.push_back(3);
        }
        for (int dirIndex: allowed) {
            Point next = cur + directions[dirIndex];
            if (next.x < 0 || next.x >= n || next.y < 0 || next.y >= n) { continue; }
            if (visited[next.x][next.y]) { continue; }
            vector<Point> nextPoints;
            switch (map[next.x][next.y]) {
                case '#':
                    continue;
                case '-':
                    if (dirIndex == 2 || dirIndex == 3) {
                        continue;
                    }
                    break;
                case '|':
                    if (dirIndex == 0 || dirIndex == 1) {
                        continue;
                    }
                    break;
                case 'X':
                    nextPoints.insert(nextPoints.end(), portals.begin(), portals.end());
            }
            if (map[next.x][next.y] >= 'A' && map[next.x][next.y] <= 'F') {
                if (cur.map & (1 << (map[next.x][next.y] - 'A'))) {
                    continue;
                }
            } else if (map[next.x][next.y] >= 'a' && map[next.x][next.y] <= 'f') {
                if (!(cur.map & (1 << (map[next.x][next.y] - 'a')))) {
                    continue;
                }
            }
            Point teleportTarget = teleport[next.x][next.y];
            if (teleportTarget.x == -2) {
                continue;
            } else if (teleportTarget.x == -1) {
                nextPoints.push_back(next);
            } else {
                nextPoints.push_back(teleportTarget);
            }
            for (Point nextPoint: nextPoints) {
                if (visited[nextPoint.x][nextPoint.y]) { continue; }
                if (map[next.x][next.y] == 'X' && nextPoint.x == next.x && nextPoint.y == next.y) { continue; }
                visited[nextPoint.x][nextPoint.y] = true;
                dis[nextPoint.x][nextPoint.y] = dis[cur.x][cur.y] + 1;
                q.push(nextPoint);
            }
        }
    }
    cout << dis[target.x][target.y] << endl;
    return 0;
}