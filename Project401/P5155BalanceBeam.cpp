//
// Created by kyang25 on 10/7/23.
//

// Luogu P5155

#include <iostream>

using namespace std;

typedef struct Point {
    int x, y;

    explicit Point(int x = 0, int y = 0) : x(x), y(y) {}

    long distanceSquared(const Point &other) const {
        return (other.x - x) * (other.x - x) + (other.y - y) * (other.y - y);
    }

    Point operator-(const Point &other) const {
        return Point(this->x - other.x, this->y - other.y);
    }

    long operator^(const Point &other) const {
        return x * other.y - y * other.x;
    }
} Point;

const float EPS = 1e-7;
const int N = 100002;

Point rewards[N];
int stack[N];
int n;
int cnt;

bool compAngle(const Point &p1, const Point &p2) {
    long tmp = (p1 - rewards[0]) ^ (p2 - rewards[0]);
    if ((float) tmp > EPS) return true;
    if ((float) tmp > -EPS && p1.distanceSquared(rewards[0]) <= p2.distanceSquared(rewards[0]))
        return true;
    return false;
}

bool compX(const Point &p1, const Point &p2) {
    return p1.x < p2.x;
}

void Graham() {
    Point p0 = rewards[0];
    int k = 0;
    for (int i = 1; i < n + 2; i++) {
        if ((p0.y > rewards[i].y) || (p0.y == rewards[i].y && p0.x > rewards[i].x)) {
            p0 = rewards[i];
            k = i;
        }
    }
    swap(rewards[k], rewards[0]);
    sort(rewards + 1, rewards + n + 2, compAngle);
    if (n + 2 == 2) {
        cnt = 2;
        stack[0] = 0;
        stack[1] = 1;
    } else {
        cnt = 2;
        stack[0] = 0;
        stack[1] = 1;
        for (int i = 2; i < n + 2; i++) {
            while (cnt > 1 &&
                   (float) (rewards[stack[cnt - 1]] - rewards[stack[cnt - 2]] ^ rewards[i] - rewards[stack[cnt - 2]]) <=
                   EPS) {
                cnt--;
            }
            stack[cnt++] = i;
        }
    }
}

int main() {
    cin >> n;
    rewards[0] = Point(0, 0);
    rewards[n + 1] = Point(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int reward;
        cin >> reward;
        rewards[i] = Point(i, reward);
    }
    Graham();
    Point convexHull[cnt];
    for (int i = 0; i < cnt; i++) {
        convexHull[i] = rewards[stack[i]];
    }
    sort(convexHull, convexHull + cnt, compX);
    for (int i = 1; i < cnt; i++) {
        int slope = 100000 * (convexHull[i].y - convexHull[i - 1].y) / (convexHull[i].x - convexHull[i - 1].x);
        int reward = 100000 * convexHull[i - 1].y;
        for (int j = 0; j < convexHull[i].x - convexHull[i - 1].x; j++) {
            if (i != 1 || j != 0) {
                cout << reward << endl;
            }
            reward += slope;
        }
    }
    return 0;
}
