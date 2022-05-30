//
// Created by Kevin Yang on 3/20/22.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int choose(int n, int k) {
        if (k == 0) {
            return 1;
        }
        return (int)(n * (long long)choose(n - 1, k - 1)) / k;
    }

    int superEggDrop(int k, int n) {
        for (int i = 0;;) {
            i++;
            for (int j = 1, sum = 0; j <= k; j++) {
                sum += choose(i, j);
                if (sum >= n) {
                    return i;
                }
            }
        }
    }
};

int main() {
    Solution solution;
    cout << solution.superEggDrop(1, 2) << endl;
    cout << solution.superEggDrop(2, 6) << endl;
    cout << solution.superEggDrop(3, 14) << endl;
    cout << solution.superEggDrop(1000, 100000) << endl;
    return 0;
}