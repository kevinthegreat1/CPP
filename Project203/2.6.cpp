//
// Created by Kevin Yang on 12/28/22.
//

#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

const int N = 100001;
int m;
int n;
int k;

typedef struct Range {
    int start;
    int end;
    set<int> used;
} Range;

bool compStart(const Range &a, const Range &b) {
    return a.start < b.start || (a.start == b.start && a.end < b.end);
}

bool compEnd(const Range &a, const Range &b) {
    return a.end < b.end || (a.end == b.end && a.start < b.start);
}

void printSet(const set<int> &set) {
    for (const int &element: set) {
        cout << element << " ";
    }
    cout << endl;
}

void printSet(const set<Range, decltype(compStart) *> &set) {
    for (const Range &range: set) {
        cout << range.start << " " << range.end << endl;
    }
}

void solve() {
    cin >> n >> k;
    set<Range, decltype(compStart) *> ranges(compStart);
    for (int i = 0; i < k; ++i) {
        int l, r;
        cin >> l >> r;
        ranges.insert({l, r});
    }
    set<Range, decltype(compStart) *> curRangesStart(compStart);
    set<Range, decltype(compEnd) *> curRangesEnd(compEnd);
    set<int> used;
    used.insert(0);
    int ans[n];
    for (int i = 0; i < n; i++) {
        // Add new ranges
        for (auto it = ranges.lower_bound({i + 1, 0}); it != ranges.upper_bound({i + 2, 0}); it++) {
            curRangesStart.insert(*it);
            curRangesEnd.insert(*it);
        }

        // Save lowest unused number
        auto adjacentFindIt = adjacent_find(used.begin(), used.end(), [](int a, int b) { return a + 1 != b; });
        int lowest = adjacentFindIt == used.end() ? (int) used.size() : *adjacentFindIt + 1;
        ans[i] = lowest;
        used.insert(lowest);

        // Remove old ranges
        int oldRangeStart = curRangesStart.empty() ? 0 : curRangesStart.begin()->start - 1;
        for (auto it = curRangesEnd.lower_bound({0, i + 1}); it != curRangesEnd.lower_bound({0, i + 2});) {
            Range oldRange = *it;
            it++;
            curRangesStart.erase(oldRange);
            curRangesEnd.erase(oldRange);
        }
        int curRangeStart = curRangesStart.empty() ? i + 1 : curRangesStart.begin()->start - 1;
        for (int j = oldRangeStart; j < curRangeStart; j++) {
            used.erase(ans[j]);
        }
        cout << ans[i];
    }
    cout << endl;
}

int main() {
    cin >> m;
    for (int i = 0; i < m; i++) {
        solve();
    }
    return 0;
}