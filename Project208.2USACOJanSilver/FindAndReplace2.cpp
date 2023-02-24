//
// Created by Kevin Yang on 1/28/23.
//

#include <iostream>
#include <set>
#include <map>

using namespace std;

int t;
string start, cur, target;
multimap<char, int> curCharToIndex;
multimap<char, int> targetCharToIndex;
set<char> unused;

void calculateMaps() {
    curCharToIndex.clear();
    targetCharToIndex.clear();
    for (int i = 0; i < start.length(); i++) {
        curCharToIndex.insert(pair<char, char>(cur[i], i));
        targetCharToIndex.insert(pair<char, char>(target[i], i));
    }
}

void calculateUnused() {
    unused.clear();
    for (char i = 'a'; i <= 'z'; i++) {
        unused.insert(i);
    }
    for (char i = 'A'; i <= 'Z'; i++) {
        unused.insert(i);
    }
    for (int i = 0; i < start.length(); i++) {
        unused.erase(cur[i]);
    }
}

int replaceIfTargetIsUnused() {
    int count = 0;
    bool loop = true;
    while (loop) {
        loop = false;
        for (int i = 0; i < start.length(); i++) {
            if (curCharToIndex.find(target[i]) == curCharToIndex.end()) {
                char replacedLetter = cur[i];
                for (int j = 0; j < start.length(); j++) {
                    if (cur[j] == replacedLetter) {
                        cur[j] = target[i];
                    }
                }
                count++;
                calculateMaps();
                loop = true;
            }
        }
    }
    return count;
}

int replaceWithDifferentLetterWithSameTarget() {
    int count = 0;
    set<int> processed;
    for (int i = 0; i < start.length(); i++) {
        if (processed.find(i) != processed.end()) {
            continue;
        }
        set<pair<char, int> > sameTargets;
        sameTargets.insert(targetCharToIndex.lower_bound(target[i]), targetCharToIndex.lower_bound(target[i] + 1));
        for (pair<char, int> sameTarget: sameTargets) {
            cur[sameTarget.second] = cur[sameTargets.begin()->second];
            processed.insert(sameTarget.second);
            count++;
        }
        count--;
    }
    return count;
}

int replaceWithUnusedLetter() {
    for (int i = 0; i < start.length(); i++) {
        if (cur[i] != target[i]) {
            char replaced = cur[i];
            for (int j = 0; j < start.length(); j++) {
                if (cur[j] == replaced) {
                    cur[j] = *unused.begin();
                }
            }
            return 1;
        }
    }
    return 0;
}

void solve() {
    curCharToIndex.clear();
    targetCharToIndex.clear();
    int count = 0;
    cin >> start >> target;
    cur = start;
    for (int i = 0; i < start.length(); i++) {
        auto it = curCharToIndex.find(start[i]);
        if (it != curCharToIndex.end() && it->second != target[i]) {
            cout << -1 << endl;
            return;
        }
        curCharToIndex.insert(pair<char, char>(cur[i], i));
    }
    calculateMaps();
    cout << "Before step 1: " << cur << " Count: " << count << endl;
    count += replaceIfTargetIsUnused();
    cout << "After step 1: " << cur << " Count: " << count << endl;
    count += replaceWithDifferentLetterWithSameTarget();
    cout << "After step 2: " << cur << " Count: " << count << endl;
    calculateMaps();
    count += replaceIfTargetIsUnused();
    cout << "After step 3: " << cur << " Count: " << count << endl;

    while (true) {
        calculateUnused();
        if (unused.empty()) {
            cout << count << endl;
            return;
        }
        count += replaceWithUnusedLetter();
        cout << "After step 4: " << cur << " Count: " << count << endl;
        calculateMaps();
        count += replaceIfTargetIsUnused();
        cout << "After step 5: " << cur << " Count: " << count << endl;
        if (cur == target) {
            cout << count << endl;
            return;
        }
    }
    cout << "After step 6: " << cur << " Count: " << count << endl;
}

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}