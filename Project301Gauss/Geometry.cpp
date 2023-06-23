#include <iostream>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

float EPS = 1e-7;

typedef struct Point {
    int x, y;

    explicit Point(int x = 0, int y = 0) : x(x), y(y) {}

    bool operator==(Point other) const {
        return this->x == other.x && this->y == other.y;
    }

    double distanceSquared(Point other) const {
        return pow(other.x - this->x, 2) + pow(other.y - this->y, 2);
    }

    double distance(Point other) const {
        return sqrt(distanceSquared(other));
    }

    Point operator+(Point other) const {
        return Point(this->x + other.x, this->y + other.y);
    }

    Point operator-(Point other) const {
        return Point(this->x - other.x, this->y - other.y);
    }

    double magnitude() const {
        return sqrt(pow(this->x, 2) + pow(this->y, 2));
    }

    double dot(Point other) const {
        return this->x * other.x + this->y * other.y;
    }
} Point;

typedef struct Line {
    Point p1, p2;

    Line(Point p1, Point p2) : p1(p1), p2(p2) {}

    double getSlope() const {
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
    int area = 0;
    for (int i = 0; i < p.n; i++) {
        area += p.vertices[i].x * p.vertices[i + 1 == p.n ? 0 : i + 1].y -
                p.vertices[i + 1 == p.n ? 0 : i + 1].x * p.vertices[i].y;
    }
    return fabs(area) / 2;
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
        ang += angle(p.vertices[i] - point, p.vertices[i + 1 == p.n ? 0 : i + 1] - point);
    }
    return fabs(fabs(ang) - 2 * M_PI) < EPS;
}

vector<Point> Graham(Point *ps, int n) {
    Point *minimum = &ps[0];
    for (int i = 1; i < n; i++) {
        if (ps[i].y <= minimum->y && ps[i].x <= minimum->x) {
            minimum = &ps[i];
        }
    }
    Point horizontal = Point(1, 0);
    map<double, Point> angleMap;
    angleMap[-1] = *minimum;
    for (int i = 0; i < n; i++) {
        if (&ps[i] == minimum) { continue; }
        double ang = angle(horizontal, ps[i] - *minimum);
        if (angleMap.find(ang) != angleMap.end()) {
            if (minimum->distanceSquared(angleMap.at(ang)) < minimum->distanceSquared(ps[i])) {
                angleMap[ang] = ps[i];
            } else { continue; }
        } else {
            angleMap[ang] = ps[i];
        }
    }
    if (angleMap.size() <= 3) {
        return {};
    }
    vector<Point> v;
    auto it = angleMap.begin();
    v.push_back(it++->second);
    v.push_back(it++->second);
    v.push_back(it++->second);
    for (; it != angleMap.end(); it++) {
        while (direction(*-- --v.end(), *--v.end(), it->second) >= 0) {
            v.pop_back();
        }
        v.push_back(it->second);
    }
    return v;
}

// Circle

int main() {
    Line l1 = Line(Point(0, 0), Point(2, 0));
    Line l2 = Line(Point(1, -1), Point(1, 1));
    Line l3 = Line(Point(1, 1), Point(1, 2));
    cout << "intersectSegment test 1: " << intersectSegment(l1, l2) << endl;
    cout << "intersectLine test 1: " << intersectLine(l1, l2) << endl;
    cout << "intersectSegment test 2: " << !intersectSegment(l1, l3) << endl;
    cout << "intersectLine test 2: " << intersectLine(l1, l3) << endl;
    cout << "intersectLineSegment test 1: " << !intersectLineSegment(l1, l3) << endl;
    cout << "intersectLineSegment test 2: " << intersectLineSegment(l3, l1) << endl;
    cout << "distance test 1: " << (distance(l1, Point(1, 1)) == 1) << endl;
    cout << "distance test 2: " << (distance(l1, Point(10, 10)) == 10) << endl;
    Polygon p1 = Polygon(new Point[4]{Point(0, 0), Point(0, 2), Point(2, 2), Point(2, 0)}, 4);
    Polygon p2 = Polygon(new Point[4]{Point(0, 0), Point(2, 0), Point(4, 2), Point(2, 2)}, 4);
    cout << "ConvexArea test 1: " << (ConvexArea(p1) == 4) << endl;
    cout << "ConvexArea test 2: " << (ConvexArea(p2) == 4) << endl;
    cout << "InConvex test 1: " << (InConvex(p1, Point(1, 1))) << endl;
    cout << "InConvex test 2: " << (!InConvex(p1, Point(3, 3))) << endl;
    cout << "InConvex test 3: " << (InConvex(p2, Point(2, 1))) << endl;
    cout << "InConvex test 4: " << (InConvex(p2, Point(3, 1))) << endl;
    cout << "InConvex test 5: " << (!InConvex(p2, Point(3, 0))) << endl;
    cout << "InConvex test 6: " << (!InConvex(p2, Point(1, 2))) << endl;
    cout << "InPolygon test 1: " << (InPolygon(p1, Point(1, 1))) << endl;
    cout << "InPolygon test 2: " << (!InPolygon(p1, Point(3, 3))) << endl;
    cout << "InPolygon test 3: " << (InPolygon(p2, Point(2, 1))) << endl;
    cout << "InPolygon test 4: " << (InPolygon(p2, Point(3, 1))) << endl;
    cout << "InPolygon test 5: " << (!InPolygon(p2, Point(3, 0))) << endl;
    cout << "InPolygon test 6: " << (!InPolygon(p2, Point(1, 2))) << endl;
    const int n = 10;
    Point ps1[n] = {Point(0, 0), Point(1, 0), Point(2, 0), Point(3, 4), Point(1, 3), Point(4, 1), Point(0, 4),
                    Point(-1, 5), Point(-2, 3), Point(-1, 1)};
    vector<Point> convexHull = Graham(ps1, n);
    cout << "Graham test 1: "
         << (convexHull.size() == 7 && convexHull[0] == Point(0, 0) && convexHull[1] == Point(2, 0) &&
             convexHull[2] == Point(4, 1) && convexHull[3] == Point(3, 4) && convexHull[4] == Point(-1, 5) &&
             convexHull[5] == Point(-2, 3) && convexHull[6] == Point(-1, 1)) << endl;
    return 0;
}