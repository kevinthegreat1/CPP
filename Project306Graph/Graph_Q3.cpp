/*
Q3: A segment and all segments which are connected with it compose a segment set. The size of a segment set is the number of segments in it. The problem is to find the size of some segment set.

Input:
n
P x1 y1 x2 y2
Q k

n表示n次操作(n<=1000)，P表示新增一条线段从(x1,y1)到(x2,y2)，Q表示查询包含第k个线段的线段集的大小


Input:
10
P 1.00 1.00 4.00 2.00
P 1.00 -2.00 8.00 4.00
Q 1
P 2.00 3.00 3.00 1.00
Q 1
Q 3
P 1.00 4.00 8.00 2.00
Q 2
P 3.00 3.00 6.00 -2.00
Q 5

Output:
1
2
2
2
5
*/

#include <iostream>

using namespace std;

const int N = 1001;

typedef struct Point {
    double x, y;

    explicit Point(double x = 0, double y = 0) : x(x), y(y) {}

    Point operator-(const Point &other) const {
        return Point(this->x - other.x, this->y - other.y);
    }

    double operator^(const Point &other) const {
        return x * other.y - y * other.x;
    }
} Point;

typedef struct Line {
    Point p1, p2;

    Line(Point p1, Point p2) : p1(p1), p2(p2) {}
} Line;

typedef struct UnionFind {
private:
    int unionFind[N];
    int setCount;
public:
    void init(int count) {
        for (int i = 0; i < count; i++) {
            unionFind[i] = i;
        }
        setCount = count;
    }

    int find(int a) {
        if (unionFind[a] == a) {
            return a;
        }
        return unionFind[a] = find(unionFind[a]);
    }

    bool isSameSet(int a, int b) {
        return find(a) == find(b);
    }

    void Union(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        unionFind[rootA] = rootB;
        setCount--;
    }
} UnionFind;

int direction(Point p1, Point p2, Point p3) {
    double dir = (p2 - p1) ^ (p3 - p2);
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

void addSegment(vector<Line> &segments, UnionFind &uf) {
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    Line line = Line(Point(x1, y1), Point(x2, y2));
    for (int i = 0; i < segments.size(); i++) {
        if (uf.isSameSet(i, segments.size())) {
            continue;
        }
        if (intersectSegment(segments[i], line)) {
            uf.Union(i, segments.size());
        }
    }
    segments.push_back(line);
}

int querySegmentSetSize(UnionFind &uf, const int &n) {
    int target;
    cin >> target;
    int targetSet = uf.find(target - 1);
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (uf.find(i) == targetSet) {
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<Line> segments;
    UnionFind uf;
    uf.init(n);
    for (int i = 0; i < n; i++) {
        char operation;
        cin >> operation;
        if (operation == 'P') {
            addSegment(segments, uf);
        } else if (operation == 'Q') {
            cout << querySegmentSetSize(uf, n) << endl;
        }
    }
    return 0;
}
