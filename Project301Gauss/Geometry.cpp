#include <cstdio>
#include <cmath>

using namespace std;

typedef struct Point {
    int x, y;

    explicit Point(int x = 0, int y = 0) : x(x), y(y) {}

    double distanceSquared(Point other) {
        return pow(other.x - this->x, 2) + pow(other.y - this->y, 2);
    }

    double distance(Point other) {
        return sqrt(distanceSquared(other));
    }

    Point add(Point other) {
        return Point(this->x + other.x, this->y + other.y);
    }

    Point sub(Point other) {
        return Point(this->x - other.x, this->y - other.y);
    }

    double magnitude() {
        return sqrt(pow(this->x, 2) + pow(this->y, 2));
    }

    double dot(Point other) {
        return this->x * other.x + this->y * other.y;
    }
} Point;

typedef struct Line {
    Point p1, p2;

    Line(Point p1, Point p2) : p1(p1), p2(p2) {}

    double getSlope() {
        return (double) (p2.y - p1.y) / (p2.x - p1.x);
    }
} Line;

int direction(Point p1, Point p2, Point p3) {
    int dir = (p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y);
    if (dir == 0) { return 0; }  // collinear
    return dir > 0 ? 1 : -1; // clockwise or counterclockwise
}

bool collinearPointOnSegment(Line l, Point q) {
    if (q.x <= fmax(l.p1.x, l.p2.x) && q.x >= fmin(l.p1.x, l.p2.x) &&
        q.y <= fmax(l.p1.y, l.p2.y) && q.y >= fmin(l.p1.y, l.p2.y)) {
        return true;
    }
    return false;
}

bool intersectSegment(Line l1, Line l2) {
    int d1 = direction(l1.p1, l1.p2, l2.p1);
    int d2 = direction(l1.p1, l1.p2, l2.p2);
    int d3 = direction(l2.p1, l2.p2, l1.p1);
    int d4 = direction(l2.p1, l2.p2, l1.p2);
    if (d1 != d2 && d3 != d4) {
        return true;
    }
    if (d1 == 0 && collinearPointOnSegment(l1, l2.p1)) { return true; }
    if (d2 == 0 && collinearPointOnSegment(l1, l2.p2)) { return true; }
    if (d3 == 0 && collinearPointOnSegment(l2, l1.p1)) { return true; }
    if (d4 == 0 && collinearPointOnSegment(l2, l1.p2)) { return true; }
    return false;
}

bool intersectLine(Line l1, Line l2) {
    return l1.getSlope() != l2.getSlope();
}

bool intersectLineSegment(Line l, Line s) {
    int d1 = direction(l.p1, l.p2, s.p1);
    int d2 = direction(l.p1, l.p2, s.p2);
    if (d1 != d2) {
        return true;
    }
    if (d1 == 0 && collinearPointOnSegment(l, s.p1)) { return true; }
    if (d2 == 0 && collinearPointOnSegment(l, s.p2)) { return true; }
    return false;
}

double distance(Line l, Point p) {
    return fabs((l.p2.x - l.p1.x) * (p.y - l.p1.y) - (l.p2.y - l.p1.y) * (p.x - l.p1.x)) /
           l.p1.distance(l.p2);
}

double angle(Point p1, Point p2) {
    return acos(p1.dot(p2) / (p1.magnitude() * p2.magnitude()));
}

typedef struct Polygon {
    Point *vertices;
    int n;

    explicit Polygon(Point *vertices, int n) : vertices(vertices), n(n) {}
} Polygon;

double ConvexArea(Polygon p) {
    double area = 0;
    for (int i = 0; i < p.n; i++) {
        area += p.vertices[i].x * p.vertices[i + 1 == p.n ? 0 : i + 1].y -
                p.vertices[i + 1 == p.n ? 0 : i + 1].x * p.vertices[i].y;
    }
    return area / 2;
}

bool InConvex(Polygon p, Point point) {
    int dir = 0;
    for (int i = 0; i < p.n; i++) {
        int curDir = direction(p.vertices[i], p.vertices[i + 1 == p.n ? 0 : i + 1], point);
        switch (dir) {
            case 0:
                dir = curDir;
                break;
            case 1:
                if (curDir < 0) { return false; }
                break;
            case -1:
                if (curDir > 0) { return false; }
                break;
        }
    }
    return true;
}

bool InPolygon(Polygon p, Point point) {
    double ang = 0;
    for (int i = 0; i < p.n; i++) {
        ang += angle(p.vertices[i].sub(point), p.vertices[i + 1 == p.n ? 0 : i + 1].sub(point));
    }
    return fabs(ang) == 2 * M_PI;
}

// Circle

const int N = 100;
Point ps[N];
int n;
int res[N], cnt;

void Graham() {

}

