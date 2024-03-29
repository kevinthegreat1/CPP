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
        return sqrt(pow(this->x, 2) + pow(this->y, 2));
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

    double distanceSquared(const Point &other) const {
        return (other.x - x) * (other.x - x) + (other.y - y) * (other.y - y);
    }

    double distance(const PointDouble &other) const {
        return sqrt(distanceSquared(other));
    }

    double distance(const Point &other) const {
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


const int N = 1001;
Point list[N];
int n;
int stack[N], cnt = 0;

//list[0]为极坐标极心的极角排序
bool cmp(const Point &p1, const Point &p2) {
    long tmp = (p1 - list[0]) ^ (p2 - list[0]);
    if ((float) tmp > EPS) return true;
    if ((float) tmp > -EPS && p1.distanceSquared(list[0]) <= p2.distanceSquared(list[0]))
        return true;
    return false;
}

//O(n*log(n))
void Graham() {
    Point p0 = list[0];
    int k = 0;
    for (int i = 1; i < n; i++) {
        if ((p0.y > list[i].y) || (p0.y == list[i].y && p0.x > list[i].x)) {
            p0 = list[i];
            k = i;
        }
    }
    swap(list[k], list[0]);
    sort(list + 1, list + n, cmp);
    if (n == 1) {
        cnt = 1;
        stack[0] = 0;
    } else if (n == 2) {
        cnt = 2;
        stack[0] = 0;
        stack[1] = 1;
    } else {
        cnt = 2;
        stack[0] = 0;
        stack[1] = 1;
        for (int i = 2; i < n; i++) {
            while (cnt > 1 &&
                   (float) (list[stack[cnt - 1]] - list[stack[cnt - 2]] ^ list[i] - list[stack[cnt - 2]]) <= EPS) {
                cnt--;
            }
            stack[cnt++] = i;
        }
    }
}

pair<Point, Point> furthestPoints(Point *convexHull) {
    Point *p1 = convexHull;
    Point *p2 = convexHull;
    long maxDistSquared = 0;
    pair<Point, Point> maxDistPoints;
    long curDistSquared = 0;
    while (true) {
        long newDistSquared = p1->distanceSquared(*(p2 + 1 == convexHull + n ? convexHull : p2 + 1));
        if (newDistSquared > curDistSquared) {
            curDistSquared = newDistSquared;
            p2 + 1 == convexHull + n ? p2 = convexHull : p2++;
            if (curDistSquared > maxDistSquared) {
                maxDistSquared = curDistSquared;
                maxDistPoints = make_pair(*p1, *p2);
            }
        } else if (p1 != convexHull + n - 1) {
            p1++;
            curDistSquared = p1->distanceSquared(*p2);
            if (curDistSquared > maxDistSquared) {
                maxDistSquared = curDistSquared;
                maxDistPoints = make_pair(*p1, *p2);
            }
        } else {
            break;
        }
    }
    return maxDistPoints;
}

double triangleArea(Point p1, Point p2, Point p3) {
    return 0.5 * abs(p1.x * p2.y + p2.x * p3.y + p3.x * p1.y - p1.x * p3.y - p2.x * p1.y - p3.x * p2.y);
}

//最远点对
//最大的三角形
double largestTriangle(const Point *convexHull, int n) {
    double area = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1, k = i + 2; j + 1 < n; j++) {
            while (k + 1 < n) {
                double cur = triangleArea(convexHull[i], convexHull[j], convexHull[k]);
                double next = triangleArea(convexHull[i], convexHull[j], convexHull[k + 1]);
                if (next > cur) {
                    k++;
                } else {
                    break;
                }
            }
            area = max(area, triangleArea(convexHull[i], convexHull[j], convexHull[k]));

        }
    }
    return area;
}

double largestTriangle2(const Point *convexHull, int n) {
    double area = 0;
    for (int i = 0; i + 2 < n; i++) {
        int j = i + 1, k = j + 1;
        while (j < n && k < n) {
            area = max(area, fabs((convexHull[j] - convexHull[i]) ^ (convexHull[k] - convexHull[i])));
            while (k < n && ((convexHull[i] - convexHull[j]) ^ (convexHull[(k + 1) % n] - convexHull[k])) < 0)
                k++;
            j++;
        }
    }
    return area;
}

//两个凸包之间的最小距离
PointDouble nearestPointToSeg(Point P, Line L) {
    PointDouble res;
    double ratio = ((P - L.p1) * (L.p2 - L.p1)) / ((L.p2 - L.p1) * (L.p2 - L.p1));
    if (ratio >= -EPS && ratio <= 1 + EPS) {
        res = PointDouble(L.p1 + (L.p2 - L.p1)) * ratio;
    } else {
        if (P.distance(L.p1) < P.distance(L.p2)) res = PointDouble(L.p1);
        else res = PointDouble(L.p2);
    }
    return res;
}

double distanceParallelSeg(Point p0, Point p1, Point p2, Point p3) {
    double res = nearestPointToSeg(p0, Line(p2, p3)).distance(p0);
    res = min(res, nearestPointToSeg(p1, Line(p2, p3)).distance(p1));
    res = min(res, nearestPointToSeg(p2, Line(p0, p1)).distance(p2));
    res = min(res, nearestPointToSeg(p3, Line(p0, p1)).distance(p3));
    return res;
}

double minDistance(const Point *convexHull1, int n, const Point *convexHull2, int m) {
    int s1 = 0, s2 = 0;
    for (int i = 0; i < n; i++) {
        if (convexHull1[i].y < convexHull1[s1].y)
            s1 = i;
    }
    for (int i = 0; i < m; i++) {
        if (convexHull2[i].y < convexHull2[s2].y)
            s2 = i;
    }
    double minDist = convexHull1[s1].distance(convexHull2[s2]);
    for (int i = 0; i < n; i++) {
        double tmp = 0;
        while ((tmp = (convexHull1[s1] - convexHull1[(s1 + 1) % n]) ^ (convexHull2[s2] - convexHull2[(s2 + 1) % m])) >
               EPS)
            s2 = (s2 + 1) % n;
        if (fabs(tmp) <= EPS) {
            minDist = min(minDist, distanceParallelSeg(convexHull1[s1], convexHull1[(s1 + 1) % n], convexHull2[s2],
                                                       convexHull2[(s2 + 1) % m]));
        } else {
            minDist = min(minDist,
                          nearestPointToSeg(convexHull2[s2], Line(convexHull1[s1], convexHull1[(s1 + 1) % n])).distance(
                                  convexHull2[s2]));
        }
        s1 = (s1 + 1) % n;
    }
    return minDist;
}

/**
 * TODO Pick公式
 * 顶点坐标都是整数简单多边形面积 = 内部点的数量 + 边上的点的数量/2 - 1
*/


int main() {
    n = 10;
    list[0] = Point(0, 0);
    list[1] = Point(1, 0);
    list[2] = Point(2, 0);
    list[3] = Point(3, 4);
    list[4] = Point(1, 3);
    list[5] = Point(4, 1);
    list[6] = Point(0, 4);
    list[7] = Point(-1, 5);
    list[8] = Point(-2, 3);
    list[9] = Point(-1, 1);
    Graham();
    Point *convexHull = new Point[cnt];
    for (int i = 0; i < cnt; i++) {
        convexHull[i] = list[stack[i]];
    }
    cout << "Graham test 1: "
         << (cnt == 7 && convexHull[0] == Point(0, 0) && convexHull[1] == Point(2, 0) &&
             convexHull[2] == Point(4, 1) && convexHull[3] == Point(3, 4) && convexHull[4] == Point(-1, 5) &&
             convexHull[5] == Point(-2, 3) && convexHull[6] == Point(-1, 1)) << endl;

    pair<Point, Point> furthestPointsPair = furthestPoints(convexHull);
    Point p1 = furthestPointsPair.first;
    Point p2 = furthestPointsPair.second;
    cout << "furthestPoints test 1: " << (p1 == Point(4, 1) && p2 == Point(-1, 5)) << endl;
    cout << "largestTriangle test 1: " << (largestTriangle(convexHull, cnt) == 10.5) << endl;
    return 0;
}
