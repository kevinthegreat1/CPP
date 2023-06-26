#include <iostream>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

float EPS = 1e-7;

typedef struct Point {
    int x, y;

    explicit Point(int x = 0, int y = 0) : x(x), y(y) {}

    bool operator==(const Point &other) const {
        return this->x == other.x && this->y == other.y;
    }

    long long distanceSquared(const Point &other) const {
        return (other.x - x) * (other.x - x) + (other.y - y) * (other.y - y);
    }

    double distance(const Point &other) const {
        return sqrt(distanceSquared(other));
    }

    Point operator+(const Point &other) const {
        return Point(this->x + other.x, this->y + other.y);
    }

    Point operator-(const Point &other) const {
        return Point(this->x - other.x, this->y - other.y);
    }

    double magnitude() const {
        return distance(Point());
        return sqrt(pow(this->x, 2) + pow(this->y, 2));
    }

    long operator*(const Point &other) const {
        return this->x * other.x + this->y * other.y;
    }

    long operator^(const Point &other) const {
        return x * other.y - y * other.x;
    }
} Point;

bool compX(const Point &p1, const Point &p2) {
    return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
}

bool compY(const Point &p1, const Point &p2) {
    return p1.y < p2.y || (p1.y == p2.y && p1.x < p2.x);
}

const int N = 100001;
Point p[N];

long long closestSquared(int left, int right) {
    long long d = INT64_MAX;
    if (left == right) return d;
    if (left + 1 == right) return p[left].distanceSquared(p[right]);
    int mid = (left + right) >> 1;
    long long d1 = closestSquared(left, mid);
    long long d2 = closestSquared(mid + 1, right);
    d = min(d1, d2);
    Point *midLeft = lower_bound(p + left, p + mid + 1, Point(p[mid].x - d, 0), compX);
    Point *midRight = upper_bound(p + mid + 1, p + right + 1, Point(p[mid].x + d, INT32_MAX), compX);
    sort(midLeft, midRight, compY);
    for (auto itHorizontal = midLeft; itHorizontal < midRight; itHorizontal++) {
        Point *midTop = lower_bound(midLeft, midRight, Point(0, itHorizontal->y - d), compY);
        Point *midBottom = upper_bound(midLeft, midRight, Point(INT32_MAX, itHorizontal->y + d), compY);
        for (auto itVertical = midTop; itVertical < midBottom; itVertical++) {
            d = min(d, itHorizontal->distanceSquared(*itVertical));
        }
    }
    return d;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &p[i].x, &p[i].y);
    sort(p, p + n, compX);
    printf("%d", closestSquared(0, n - 1));
}

