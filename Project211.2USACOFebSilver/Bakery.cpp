//
// Created by Kevin Yang on 2/25/23.
//

#include <iostream>
#include <cmath>

using namespace std;

const int N = 101;
long long t, n, cookieTime, muffinTime;

typedef struct Order {
    long long cookies, muffins, waitTime;
} Order;

Order orders[N];

pair<long long, long long> getValidInterval(int i, long long moonies) {
    // (cookieTime - a)*cookies + (muffintime - (moonies - a))*muffin <= waittime
    // cookieTime*cookies - a*cookies + muffintime*muffin - moonies*muffin + a*muffin <= waittime

    // a*(muffin-cookies) + cookieTime*cookies + muffintime*muffin - moonies*muffin <= waittime
    // a*(muffin-cookies) <= waittime - cookieTime*cookies - muffintime*muffin + moonies*muffin
    // if (muffin-cookies) > 0
    // a <= (waittime - cookieTime*cookies - muffintime*muffin + moonies*muffin) / (muffin-cookies)
    // else if (muffin-cookies) < 0
    // a >= (waittime - cookieTime*cookies - muffintime*muffin + moonies*muffin) / (muffin-cookies)
    // else if (muffin-cookies) == 0
    // 0 <= (waittime - cookieTime*cookies - muffintime*muffin + moonies*muffin)
    Order curOrder = orders[i];
    if (curOrder.muffins - curOrder.cookies > 0) {
        return make_pair(0, (long long) floor((double) (curOrder.waitTime - cookieTime * curOrder.cookies -
                                                        muffinTime * curOrder.muffins +
                                                        moonies * curOrder.muffins) /
                                              (curOrder.muffins - curOrder.cookies)));
    } else if (curOrder.muffins - curOrder.cookies < 0) {
        return make_pair(
                (long long) ceil(
                        (double) (curOrder.waitTime - cookieTime * curOrder.cookies - muffinTime * curOrder.muffins +
                                  moonies * curOrder.muffins) / (curOrder.muffins - curOrder.cookies)), cookieTime + muffinTime);
    } else {
        if (curOrder.waitTime - cookieTime * curOrder.cookies - muffinTime * curOrder.muffins +
            moonies * curOrder.muffins >= 0) {
            return make_pair(0, cookieTime + muffinTime);
        } else {
            return make_pair(-1, -1);
        }
    }
}

long long binarySearch(long long start, long long end) {
    if (start == end) {
        return start;
    }
    long long mid = (start + end) / 2;
    bool valid = true;
    pair<long long, long long> interval = make_pair(max(0LL, mid - muffinTime + 1), min(cookieTime - 1, mid));
    for (int i = 0; i < n; i++) {
        auto newInterval = getValidInterval(i, mid);
//        cout << "bounds: " << newInterval.first << " " << newInterval.second << endl;
        interval.first = max(interval.first, newInterval.first);
        interval.second = min(interval.second, newInterval.second);
        if (interval.first > interval.second) {
            valid = false;
            break;
        }
    }
    if (valid) {
        return binarySearch(start, mid); // try with less moonies
    } else {
        return binarySearch(mid + 1, end); // try with more moonies
    }
}

void solve() {
    cin >> n >> cookieTime >> muffinTime;
    for (int i = 0; i < n; i++) {
        cin >> orders[i].cookies >> orders[i].muffins >> orders[i].waitTime;
    }
    cout << binarySearch(0, cookieTime + muffinTime - 2) << endl;
}

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}