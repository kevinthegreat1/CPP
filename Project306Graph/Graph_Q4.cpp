/*
Q4: 在二维平面上控制一架飞机，目标是从起点移动到终点，飞机需要无线信号才能移动，有一些信号基站坐落在平面上，对于每一个基站都有一个坐标D和信号半径R，只有当飞机距离坐标D的距离小于等于R时才能获得信号，求从起点到终点的最短距离
输入一个n表示有n个基站，接下来n行每行三个数表示横坐标、纵坐标和信号半径，第一个基站是起点，最后一个基站是终点
Input:
2
0 0 1
2 0 1
Output:
2
*/

#include <iostream>
#include <set>
#include <map>
#include <queue>

using namespace std;

const float EPS = 1e-7;
const int N = 601; // Total possible number of points

typedef struct Point {
    double x, y;

    explicit Point(double x = 0, double y = 0) : x(x), y(y) {}

    bool operator==(const Point &other) const {
        return fabs(this->x - other.x) < EPS && fabs(this->y - other.y) < EPS;
    }

    bool operator<(const Point &other) const {
        return this->x < other.x || (fabs(this->x - other.x) < EPS && this->y < other.y);
    }

    double distanceSquared(const Point &other) const {
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

    Point operator*(const double &scale) const {
        return Point(this->x * scale, this->y * scale);
    }

    double operator*(const Point &other) const {
        return this->x * other.x + this->y * other.y;
    }

    Point operator/(const double &scale) const {
        return Point(this->x / scale, this->y / scale);
    }

    double operator^(const Point &other) const {
        return x * other.y - y * other.x;
    }

    Point mirrorDiagonally() const {
        return Point(y, x);
    }
} Point;

typedef struct Line {
    Point p1, p2;

    Line(Point p1, Point p2) : p1(p1), p2(p2) {}

    double getSlope() const {
        return (double) (p2.y - p1.y) / (p2.x - p1.x);
    }
} Line;

typedef struct Circle {
    Point c;
    double r;

    explicit Circle(Point c = Point(), double r = 0) : c(c), r(r) {}

    bool operator==(const Circle &other) const {
        return c == other.c && fabs(r - other.r) < EPS;
    }
} Circle;

typedef struct Edge {
    int from;
    int to;
    int cost;
    int totalCost;

    explicit Edge(const int &from = 0, const int &to = 0, const int &cost = 0, const int &totalCost = 0) : from(from),
                                                                                                           to(to),
                                                                                                           cost(cost),
                                                                                                           totalCost(
                                                                                                                   totalCost) {}

    bool operator<(const Edge &other) const {
        return totalCost > other.totalCost || (totalCost == other.totalCost && cost > other.cost) ||
               (totalCost == other.totalCost && cost == other.cost && from > other.from) ||
               (totalCost == other.totalCost && cost == other.cost && from == other.from && to > other.to);
    }
} Edge;

int getEdges(const vector<Circle> &circles, map<int, vector<Edge>> &edges) {
    // Add the starting and ending points
    vector<Point> points;
    points.push_back(circles[0].c);
    points.push_back(circles[circles.size() - 1].c);
    // Find all intersection points between all circles
    for (Circle circle: circles) {
        for (Circle circle2: circles) {
            if (circle == circle2) {
                continue;
            }
            Point p1 = circle.c, p2 = circle2.c;
            double r1 = circle.r, r2 = circle2.r;
            double distanceSquared = p1.distanceSquared(p2);
            double a = 2 * (r1 * r1 + r2 * r2) / (distanceSquared) -
                       pow(r1 * r1 - r2 * r2, 2) / (distanceSquared * distanceSquared) - 1;
            if (a < 0) {
                continue;
            }
            Point b = ((p1 + p2) / 2 + (p2 - p1) * (r1 * r1 - r2 * r2) / (2 * distanceSquared));
            Point c = (p2 - p1).mirrorDiagonally() * a / 2;
            if (c.magnitude() < EPS) {
                points.push_back(b);
            } else {
                points.push_back(b + c);
                points.push_back(b - c);
            }
        }
    }
    // Find all edges between all points which are completely inside the circle
    for (int i = 1; i < points.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (i == j) {
                continue;
            }
            Point point = points[i];
            Point point2 = points[j];
            Line line(point, point2);
            vector<pair<double, double>> coveredSegments;
            for (Circle circle: circles) {
                // dr = p1.distance(p2)
                // D = p1 ^ p2
                // if r^2 dr^2 - D^2 <= 0, no intersection or is tangent
                // x = (D dy +- sign(dy) dx sqrt(dr^2 r^2 - D^2) / dr^2)
                // y = (-D dx +- abs(dy) dx sqrt(dr^2 r^2 - D^2) / dr^2)
                double dr = point.distance(point2);
                double D = point ^ point2;
                double discriminant = dr * dr * circle.r * circle.r - D * D;
                if (discriminant < -EPS) {
                    continue;
                }
                double dx = point2.x - point.x;
                double dy = point2.y - point.y;
                double x1 = (D * dy + dx * sqrt(discriminant)) / (dr * dr);
                double x2 = (D * dy - dx * sqrt(discriminant)) / (dr * dr);
                double y1 = (-D * dx + fabs(dy) * sqrt(discriminant)) / (dr * dr);
                double y2 = (-D * dx - fabs(dy) * sqrt(discriminant)) / (dr * dr);

                x1 += circle.c.x;
                x2 += circle.c.x;
                y1 += circle.c.y;
                y2 += circle.c.y;

                // Normalize the points to 0 to 1
                if (!(point < point2)) {
                    swap(point, point2);
                }
                double dx1 = x1 - point.x;
                double dx2 = x2 - point.x;
                double d1 = dx1 / dx;
                double d2 = dx2 / dx;
                if (d1 > d2) {
                    swap(d1, d2);
                }
                coveredSegments.emplace_back(d1, d2);
            }
            sort(coveredSegments.begin(), coveredSegments.end(),
                 [](pair<double, double> a, pair<double, double> b) {
                     return a.first < b.first || (a.first == b.first && a.second < b.second);
                 });
            bool covered = true;
            for (int i = 0; i < coveredSegments.size() - 1; i++) {
                if (coveredSegments[i + 1].first - coveredSegments[i].second > EPS) {
                    covered = false;
                    break;
                }
            }
            double distance = point.distance(point2);
            if (covered && distance != 0) {
                edges[i].emplace_back(i, j, distance, distance);
                edges[j].emplace_back(j, i, distance, distance);
            }
        }
    }
    return points.size();
}

void spfa(const int &n, int *totalCosts, map<int, vector<Edge>> &edges) {
    priority_queue<Edge> curEdges;
    int count = 1;
    memset(totalCosts, -1, sizeof(*totalCosts) * n);
    curEdges.emplace();
    while (!curEdges.empty()) {
        Edge curEdge = curEdges.top();
        curEdges.pop();
        if (totalCosts[curEdge.to] >= 0) {
            continue;
        }
        for (Edge edge: edges[curEdge.to]) {
            if (totalCosts[edge.to] < 0) {
                edge.totalCost = curEdge.totalCost + edge.cost;
                curEdges.push(edge);
            }
        }
        totalCosts[curEdge.to] = curEdge.totalCost;
        if (count++ == n) {
            break;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<Circle> circles;
    for (int i = 0; i < n; i++) {
        Circle c = Circle();
        cin >> c.c.x >> c.c.y >> c.r;
        circles.push_back(c);
    }
    map<int, vector<Edge>> edges;
    int p = getEdges(circles, edges);
    int costs[N];
    spfa(p, costs, edges);
    cout << costs[1] << endl;
    return 0;
}
