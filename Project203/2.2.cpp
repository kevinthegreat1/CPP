//
// Created by Kevin Yang on 12/26/22.
//

#include <iostream>
#include <set>

using namespace std;

int m;
int n;
int n3;

typedef struct Point {
    int index, x;

    Point(int index, int x) : index(index), x(x) {}
} Point;

bool comp(Point p1, Point p2) {
    return p1.x < p2.x || (p1.x == p2.x && p1.index < p2.index);
}

set<Point, decltype(comp) *> points(comp);

void solve() {
    cin >> n;
    n3 = 3 * n;
    for (int i = 1; i <= n3; i++) {
        int x, y;
        cin >> x >> y;
        points.insert({i, x});
    }
    auto it = points.begin();
    for (; it != points.end();) {
        for (int i = 0; i < 3; i++, it++) {
            cout << it->index << " ";
        }
        cout << endl;
    }
}

int main() {
    cin >> m;
    for (int i = 0; i < m; i++) {
        solve();
    }
    return 0;
}