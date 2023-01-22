//
// Created by Kevin Yang on 12/26/22.
//

#include <iostream>
#include <vector>

using namespace std;

const int N = 101;
int n;
int targets[N];

void get(int target) {
    if (target < 3) {
        cout << target << " " << -1 << endl;
        return;
    }
    vector<int> factors;
    for (int i = 1; i * i <= target; i++) {
        if (target % i == 0) {
            factors.push_back(i);
            factors.push_back(target / i);
        }
    }
    int max = 0;
    int f1, f2, f3;
    for (int i = 0; i < factors.size(); i++) {
        for (int j = i; j < factors.size(); j++) {
            int factor1 = factors[i];
            int factor2 = factors[j];
            int factor3 = target - factor1 - factor2;
            if (factor3 > 0 && target % factor3 == 0) {
                int product = factor1 * factor2 * factor3;
                if (product > max) {
                    max = product;
                    f1 = factor1;
                    f2 = factor2;
                    f3 = factor3;
                }
            }
        }
    }
    if (max == 0) {
        cout << target << " " << -1 << endl;
    } else {
        cout << target << " " << max << " " << f1 << " " << f2 << " " << f3 << endl;
    }
}

int main() {
    cin >> n;
//    for (int i = 0; i < n; i++) {
//        cin >> targets[i];
//    }
    for (int i = 1; i <= 100; i++) {
        targets[i - 1] = i;
    }
    for (int target: targets) {
        if (target == 0) {
            break;
        }
        get(target);
    }
    return 0;
}