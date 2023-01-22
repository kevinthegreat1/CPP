//
// Created by Kevin Yang on 12/19/22.
//

#include <iostream>

using namespace std;

struct tv {
    int start;
    int end;
};

bool compare(tv a, tv b) {
    return a.end < b.end || (a.end == b.end && a.start > b.start);
}

int main() {
    int n;
    cin >> n;
    tv tvs[1001];
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        tvs[i].start = a;
        tvs[i].end = b;
    }
    sort(tvs, tvs + n, compare);
    int count = 0, curTime = 0;
    for (int i = 0; i < n; i++) {
        if (tvs[i].start >= curTime) {
            count++;
            curTime = tvs[i].end;
        }
    }
    cout << count;
    return 0;
}