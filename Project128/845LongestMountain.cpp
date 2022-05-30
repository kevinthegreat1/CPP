//
// Created by Kevin Yang on 1/30/22.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    enum state {
        NONE, UP, DOWN
    };

public:
    int longestMountain(vector<int> &arr) {
        state state = NONE;
        int cur = 0, longest = 0;
        for (int i = 0; i < arr.size() - 1; i++) {
            switch (state) {
                case NONE:
                    if (arr[i + 1] > arr[i]) {
                        cur++;
                        state = UP;
                    }
                    break;
                case UP:
                    if (arr[i + 1] > arr[i]) {
                        cur++;
                    } else if (arr[i + 1] < arr[i]) {
                        cur++;
                        state = DOWN;
                    } else {
                        state = NONE;
                        cur = 0;
                    }
                    break;
                case DOWN:
                    if (arr[i + 1] < arr[i]) {
                        cur++;
                    } else {
                        state = NONE;
                        longest = max(cur, longest);
                        cur = 0;
                        i--;
                    }
                    break;
            }
        }
        if (state == DOWN) {
            longest = max(cur, longest);
        }
        return longest == 0 ? 0 : longest + 1;
    }
};

int main(){
    Solution solution;
    vector<int> arr={875,884,239,731,723,685};
    cout << solution.longestMountain(arr);
}