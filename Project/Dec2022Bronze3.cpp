//
// Created by kyang25 on 1/23/23.
//

#include <iostream>
#include <vector>

using namespace std;

const int N = 101;
int t, n, m;

// inputs not yet determined to be distinguishable or not
vector<string> inputsResultingInZero, inputsResultingInOne;

// -1 means not distinguishable
// 0 means 0 at pos j results in 0
// 1 means 0 at pos j results in 1
// 2 means 1 at pos j results in 0
// 3 means 1 at pos j results in 1
// 4 means 0 at pos j results in 0 and 1 at pos j results in 1
// 5 means 1 at pos j results in 0 and 0 at pos j results in 1
int isDistinguishableAt(int j) {
    bool zeroUsedByZero = false, zeroUsedByOne = false, oneUsedByZero = false, oneUsedByOne = false;
    for (const string &zeroInput: inputsResultingInZero) {
        if (zeroInput[j] == '0') {
            zeroUsedByZero = true;
        } else {
            oneUsedByZero = true;
        }
    }
    for (const string &oneInput: inputsResultingInOne) {
        if (oneInput[j] == '0') {
            zeroUsedByOne = true;
        } else {
            oneUsedByOne = true;
        }
    }
    if (zeroUsedByZero && !zeroUsedByOne && oneUsedByOne && !oneUsedByZero) {
        return 4;
    } else if (zeroUsedByOne && !zeroUsedByZero && oneUsedByZero && !oneUsedByOne) {
        return 5;
    } else if (zeroUsedByZero && !zeroUsedByOne) {
        return 0;
    } else if (zeroUsedByOne && !zeroUsedByZero) {
        return 1;
    } else if (oneUsedByZero && !oneUsedByOne) {
        return 2;
    } else if (oneUsedByOne && !oneUsedByZero) {
        return 3;
    }
    return -1;
}

void removeElementsMatchingAt(vector<string> &inputs, char value, int j) {
    auto it = inputs.begin();
    while (it != inputs.end()) {
        if ((*it)[j] == value) {
            it = inputs.erase(it);
        } else {
            it++;
        }
    }
}

void solve() {
    inputsResultingInZero.clear();
    inputsResultingInOne.clear();
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        string input;
        bool programResult;
        cin >> input >> programResult;
        if (programResult) {
            inputsResultingInOne.push_back(input);
        } else {
            inputsResultingInZero.push_back(input);
        }
    }
    while (!inputsResultingInZero.empty() && !inputsResultingInOne.empty()) {
        vector<string> inputsResultingInZeroCopy(inputsResultingInZero), inputsResultingInOneCopy(inputsResultingInOne);
        for (int j = 0; j < n; j++) {
            switch (isDistinguishableAt(j)) {
                case 0: {
                    removeElementsMatchingAt(inputsResultingInZero, '0', j);
                    break;
                }
                case 1: {
                    removeElementsMatchingAt(inputsResultingInOne, '0', j);
                    break;
                }
                case 2: {
                    removeElementsMatchingAt(inputsResultingInZero, '1', j);
                    break;
                }
                case 3: {
                    removeElementsMatchingAt(inputsResultingInOne, '1', j);
                    break;
                }
                case 4: {

                }
                case 5: {
                    cout << "OK" << endl;
                    return;
                }
            }
        }
        if (inputsResultingInZeroCopy == inputsResultingInZero && inputsResultingInOneCopy == inputsResultingInOne) {
            break;
        }
    }
    if (inputsResultingInZero.empty() || inputsResultingInOne.empty()) {
        cout << "OK" << endl;
    } else {
        cout << "LIE" << endl;
    }
}

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}