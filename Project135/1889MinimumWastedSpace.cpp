//
// Created by Kevin Yang on 4/3/22.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minWastedSpace(vector<int> &packages, vector<vector<int>> &boxes) {
        sort(packages.begin(), packages.end());
        long minWaste = INT32_MAX;
        for (vector<int> supplier: boxes) {
            sort(supplier.begin(), supplier.end());
            long curWaste = 0;
            int prev = supplier[0];
            for (int package: packages) {
                if (package > prev) {
                    auto it = lower_bound(supplier.begin(), supplier.end(), package);
                    if (it == supplier.end()) {
                        curWaste = INT32_MAX;
                        break;
                    } else {
                        prev = *it;
                    }
                }
                curWaste += prev - package;
            }
            minWaste = min(curWaste, minWaste);
        }
        return minWaste == INT32_MAX ? -1 : minWaste % 1000000007;
    }
};

int main() {
    Solution solution;
    vector<int> packages1 = {2, 3, 5};
    vector<vector<int>> boxes1 = {{4, 8},
                                  {2, 8}};
    vector<int> packages2 = {2, 3, 5};
    vector<vector<int>> boxes2 = {{1, 4},
                                  {2, 3},
                                  {3, 4}};
    vector<int> packages3 = {3, 5, 8, 10, 11, 12};
    vector<vector<int>> boxes3 = {{12},
                                  {11, 9},
                                  {10, 5, 14}};
    vector<int> packages4 = {1, 8, 9, 2, 7};
    vector<vector<int>> boxes4 = {{9},
                                  {10, 6},
                                  {2}};
    cout << solution.minWastedSpace(packages4, boxes4);
    return 0;
}