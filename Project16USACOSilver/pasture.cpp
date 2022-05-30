#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> point;

bool ycomp(point a, point b){
    return a.second < b.second;
}

int sum(int x1, int x2, int y1, int y2){
    return 0;
}

int main() {
    int n, i;
    cin >> n;
    point p[n];
    for (i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    sort(p, p + n);
    for (i = 0; i < n; i++) {
        p[i].first = i;
    }
    sort(p, p + n, ycomp);
    for (i = 0; i < n; i++) {
        p[i].second = i;
    }
    return 0;
}