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


//最远点对
//最大的三角形
//两个凸包之间的最小距离


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
    cout << "Graham test 1: "
         << (cnt == 7 && list[stack[0]] == Point(0, 0) && list[stack[1]] == Point(2, 0) &&
             list[stack[2]] == Point(4, 1) && list[stack[3]] == Point(3, 4) && list[stack[4]] == Point(-1, 5) &&
             list[stack[5]] == Point(-2, 3) && list[stack[6]] == Point(-1, 1)) << endl;
    return 0;
}
