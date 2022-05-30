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
        vector<long long> sum(packages.size());
        sum[0] = packages[0];
        for (int i = 1; i < packages.size(); i++) {
            sum[i] = sum[i - 1] + packages[i];
        }
        long long minWaste = INT64_MAX;
        for (vector<int> supplier: boxes) {
            sort(supplier.begin(), supplier.end());
            auto box = lower_bound(supplier.begin(), supplier.end(), packages[0]);
            if (box == supplier.end()) {
                continue;
            }
            auto prev = packages.begin();
            long long curWaste = *box - packages[0];
            for (; box != supplier.end(); box++) {
                auto package = upper_bound(packages.begin(), packages.end(), *box);
                if (package == packages.begin()) {
                    continue;
                }
                package--;
                curWaste += (package - prev) * *box - (*(sum.begin() + (package - packages.begin())) - *(sum.begin() + (prev - packages.begin())));
                prev = package;
            }
            if (prev + 1 == packages.end()) {
                minWaste = min(curWaste, minWaste);
            }
        }
        return minWaste == INT64_MAX ? -1 : minWaste % 1000000007;
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