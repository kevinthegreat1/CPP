//
// Created by Kevin Yang on 2/25/23.
//

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100001;
int g, n;

typedef struct State {
    int x, y, t;

    bool operator<(const State &other) const {
        return t < other.t;
    }

    bool operator<=(const State &other) const {
        return t <= other.t;
    }
} State;

State grazing[N];
State alibi[N];

long long getDistanceSquared(const State &a, const State &b) {
    return (a.x - b.x) * 1LL * (a.x - b.x) + (a.y - b.y) * 1LL * (a.y - b.y);
}

bool canTravelBetween(const State &a, const State &b) {
    return getDistanceSquared(a, b) <= (b.t - a.t) * 1LL * (b.t - a.t);
}

int main() {
    cin >> g >> n;
    for (int i = 0; i < g; i++) {
        cin >> grazing[i].x >> grazing[i].y >> grazing[i].t;
    }
    for (int i = 0; i < n; i++) {
        cin >> alibi[i].x >> alibi[i].y >> alibi[i].t;
    }
    sort(grazing, grazing + g);
    int invalidAlibiCount = 0;
    for (int i = 0; i < n; i++) {
        if (grazing[0] < alibi[i] && !canTravelBetween(alibi[i], *(upper_bound(grazing, grazing + g, alibi[i]) - 1))) {
            continue;
        }
        if (alibi[i] <= grazing[g - 1] && !canTravelBetween(alibi[i], *lower_bound(grazing, grazing + g, alibi[i]))) {
            continue;
        }
        invalidAlibiCount++;
    }
    cout << n - invalidAlibiCount << endl;
    return 0;
}