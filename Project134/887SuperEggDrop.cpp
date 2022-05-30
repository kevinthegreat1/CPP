//
// Created by Kevin Yang on 3/20/22.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
private:
    map<pair<int, int>, int> map;

public:
    int superEggDrop(int k, int n) {
        if (k == 1) {
            return n;
        }
        if (n == 0) {
            return 0;
        }
        if (k == 2) {
            return floor(sqrt(2 * n) + (float) 1 / 2);
        }
        auto ansIt = map.find({k, n});
        if (ansIt != map.end()) {
            return ansIt->second;
        }
        int ans = INT32_MAX;
        for (int i = 0; i < n; i++) {
            ans = min(ans, max(superEggDrop(k - 1, i), superEggDrop(k, n - i - 1)) + 1);
        }
        map[{k, n}] = ans;
        return ans;
    }
};

int main() {
    Solution solution;
    cout << solution.superEggDrop(1, 2) << endl;
    cout << solution.superEggDrop(2, 6) << endl;
    cout << solution.superEggDrop(3, 14) << endl;
    return 0;
}