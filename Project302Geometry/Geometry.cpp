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

    long distanceSquared(const Point &other) const {
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
    }

    long operator*(const Point &other) const {
        return this->x * other.x + this->y * other.y;
    }

    long operator^(const Point &other) const {
        return x * other.y - y * other.x;
    }
} Point;

typedef struct PointDouble {
    double x, y;

    explicit PointDouble(double x = 0, double y = 0) : x(x), y(y) {}

    explicit PointDouble(Point p) : x(p.x), y(p.y) {}

    bool operator==(const PointDouble &other) const {
        return fabs(this->x - other.x) < EPS && fabs(this->y - other.y) < EPS;
    }

    double distanceSquared(const PointDouble &other) const {
        return (other.x - x) * (other.x - x) + (other.y - y) * (other.y - y);
    }

    double distance(const PointDouble &other) const {
        return sqrt(distanceSquared(other));
    }

    PointDouble operator*(const double &other) const {
        return PointDouble(x * other, y * other);
    }
} PointDouble;

typedef struct Line {
    Point p1, p2;

    Line(Point p1, Point p2) : p1(p1), p2(p2) {}

    double getSlope() const {
        return (double) (p2.y - p1.y) / (p2.x - p1.x);
    }
} Line;

int direction(Point p1, Point p2, Point p3) {
    long dir = (p2 - p1) ^ (p3 - p2);
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
    return acos((double) (p1 * p2) / (p1.magnitude() * p2.magnitude()));
}

typedef struct Polygon {
    Point *vertices;
    int n;

    explicit Polygon(Point *vertices, int n) : vertices(vertices), n(n) {}
} Polygon;

double ConvexArea(Polygon p) {
    long area = 0;
    for (int i = 0; i < p.n; i++) {
        area += p.vertices[i] ^ p.vertices[(i + 1) % p.n];
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

// 圆
// 三个点求一个圆
// 两个相交的圆的重叠面积
// 过一个点求圆的切线

typedef struct Circle {
    PointDouble c;
    double r;

    explicit Circle(PointDouble c = PointDouble(), double r = 0) : c(c), r(r) {}
} Circle;

Circle ofPoints(Point p1, Point p2, Point p3) {
    double a = p1.x * (p2.y - p3.y) - p1.y * (p2.x - p3.x) + p2.x * p3.y - p3.x * p2.y;
    if (a == 0) {
        return Circle();
    }
    double a1 = p1.x * p1.x + p1.y * p1.y;
    double a2 = p2.x * p2.x + p2.y * p2.y;
    double a3 = p3.x * p3.x + p3.y * p3.y;
    double b = a1 * (p2.y - p3.y) + a2 * (p3.y - p1.y) + a3 * (p1.y - p2.y);
    double c = a1 * (p3.x - p2.x) + a2 * (p1.x - p3.x) + a3 * (p2.x - p1.x);
    double d = a1 * (p2.x * p3.y - p3.x * p2.y) + a2 * (p3.x * p1.y - p1.x * p3.y) + a3 * (p1.x * p2.y - p2.x * p1.y);
    double x = b / (2 * a);
    double y = c / (2 * a);
    double r = sqrt((b * b + c * c + 4 * a * d) / (4 * a * a));
    return Circle(PointDouble(x, y), r);
}

PointDouble outerCenter(Point p1, Point p2, Point p3) {
    double a1 = p2.x - p1.x, b1 = p2.y - p1.y, c1 = (a1 * a1 + b1 * b1) / 2;
    double a2 = p3.x - p1.x, b2 = p3.y - p1.y, c2 = (a2 * a2 + b2 * b2) / 2;
    double d = a1 * b2 - a2 * b1;
    return PointDouble(
            p1.x + (c1 * b2 - c2 * b1) / d,
            p1.y + (a1 * c2 - c1 * a2) / d
    );
}

double overlappingArea(Circle c1, Circle c2) {
    double d = c1.c.distance(c2.c);
    if (d >= c1.r + c2.r) {
        return 0;
    }
    if (d <= fabs(c1.r - c2.r)) {
        return M_PI * min(c1.r, c2.r) * min(c1.r, c2.r);
    }
    double t1 = acos((d * d + c1.r * c1.r - c2.r * c2.r) / (2 * d * c1.r));
    double t2 = acos((d * d + c2.r * c2.r - c1.r * c1.r) / (2 * d * c2.r));
    return c1.r * c1.r * t1 +
           c2.r * c2.r * t2 -
           // 0.5 * sqrt((-d + c1.r + c2.r) * (d + c1.r - c2.r) * (d - c1.r + c2.r) * (d + c1.r + c2.r))
           d * c1.r * sin(t1);
}

pair<PointDouble, PointDouble> getTangentPoints(Circle c, Point p) {
    double dx = p.x - c.c.x;
    double dy = p.y - c.c.y;
    double d = sqrt(dx * dx + dy * dy);
    if (d >= c.r) {
        double rho = c.r / d;
        double ad = rho * rho;
        double bd = rho * sqrt(1 - rho * rho);
        double t1x = c.c.x + ad * dx - bd * dy;
        double t1y = c.c.y + ad * dy + bd * dx;
        double t2x = c.c.x + ad * dx + bd * dy;
        double t2y = c.c.y + ad * dy - bd * dx;
        return make_pair(PointDouble(t1x, t1y), PointDouble(t2x, t2y));
    }
    return make_pair(PointDouble(), PointDouble());
}

//定积分
// 函数->曲线->曲线和x轴所夹的面积
// simpson
double f(double x) { return x; }

double simpson(double a, double b) {
    double c = a + (b - a) / 2;
    return (f(a) + 4 * f(c) + f(b)) * (b - a) / 6;
}

double asr(double left, double right, double eps, double prevValue) {
    double mid = (left + right) / 2;
    double leftValue = simpson(left, mid), rightValue = simpson(mid, right);
    if (fabs(leftValue + rightValue - prevValue) < eps * 15)
        return leftValue + rightValue + (leftValue + rightValue - prevValue) / 15;
    return asr(left, mid, eps / 2, leftValue) + asr(mid, right, eps / 2, rightValue);
}

double asr(double left, double right, double eps) {
    return asr(left, right, eps, simpson(left, right));
}

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
    Circle c1 = ofPoints(Point(1, 0), Point(0, 1), Point(-1, 0));
    Circle c2 = ofPoints(Point(4, 0), Point(2, 2), Point(0, 0));
    cout << "Circle.ofPoints test 1: " << (c1.c == PointDouble(0, 0) && c1.r == 1) << endl;
    cout << "Circle.ofPoints test 2: " << (c2.c == PointDouble(2, 0) && c2.r == 2) << endl;
    Circle c3 = Circle(PointDouble(0, 0), 2);
    Circle c4 = Circle(PointDouble(2, 0), 1);
    cout << "Circle.overlappingArea test 1: " << (fabs(fabs(overlappingArea(c3, c4)) - 1.40306643969) <= 1e-9) << endl;
    pair<PointDouble, PointDouble> p = getTangentPoints(c3, Point(2, 2));
    cout << "Circle.getTangentPoints test 1: " << (p.first == PointDouble(0, 2) && p.second == PointDouble(2, 0))
         << endl;
    return 0;
}