//
// Created by Kevin Yang on 1/28/23.
//

#include <iostream>
#include <set>
#include <map>

using namespace std;

int t;
string start, target;
map<char, char> requiredTransformations;
set<char> unusedByStart, unusedByBoth;

void solve() {
    requiredTransformations.clear();
    unusedByStart.clear();
    unusedByBoth.clear();
    for (char i = 'a'; i <= 'z'; i++) {
        unusedByStart.insert(i);
        unusedByBoth.insert(i);
    }
    for (char i = 'A'; i <= 'Z'; i++) {
        unusedByStart.insert(i);
        unusedByBoth.insert(i);
    }
    cin >> start >> target;
    for (int i = 0; i < start.length(); i++) {
        auto it = requiredTransformations.find(start[i]);
        if (it != requiredTransformations.end() && it->second != target[i]) {
            cout << -1 << endl;
            return;
        }
        if (start[i] != target[i]) {
            requiredTransformations.insert(pair<char, char>(start[i], target[i]));
        }
        unusedByStart.erase(start[i]);
        unusedByBoth.erase(start[i]);
        unusedByBoth.erase(target[i]);
    }
    int count = 0;
    while (!requiredTransformations.empty()) {
        auto interferenceIt = requiredTransformations.find(requiredTransformations.begin()->second);
        auto transformationIt = requiredTransformations.begin();
        for (; transformationIt != requiredTransformations.end(); transformationIt++) {
            interferenceIt = requiredTransformations.find(transformationIt->second);
            if (interferenceIt == requiredTransformations.end()) {
                break;
            }
        }
        if (transformationIt == requiredTransformations.end()) {
            transformationIt = requiredTransformations.begin();
            interferenceIt = requiredTransformations.find(transformationIt->second);
        }
        if (interferenceIt != requiredTransformations.end()) {
            char interferedTarget = interferenceIt->second;
            if (unusedByStart.empty()) {
                cout << -1 << endl;
                return;
            }
            if (!unusedByBoth.empty()) {
                requiredTransformations.insert(pair<char, char>(*unusedByBoth.begin(), interferedTarget));
                unusedByStart.erase(*unusedByBoth.begin());
                unusedByBoth.erase(unusedByBoth.begin());
            } else {
                requiredTransformations.insert(pair<char, char>(*unusedByStart.begin(), interferedTarget));
                unusedByStart.erase(unusedByStart.begin());
                unusedByBoth.erase(*unusedByStart.begin());
            }
            requiredTransformations.erase(interferenceIt);
            count++;
        }
        unusedByStart.insert(transformationIt->first);
        unusedByStart.erase(transformationIt->second);
        unusedByBoth.insert(transformationIt->first);
        unusedByBoth.erase(transformationIt->second);
        requiredTransformations.erase(transformationIt);
        count++;
    }
    cout << count << endl;
}

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}