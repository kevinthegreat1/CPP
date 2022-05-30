//
// Created by Kevin Yang on 5/8/21.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            if (rev < INT_MIN / 10 || rev > INT_MAX / 10) {
                return 0;
            }
            rev = (rev * 10) + (x % 10);
            x /= 10;
        }
        return rev;
    }
};

int main(){
    Solution solution;
    cout<<solution.reverse(123);
    return 0;
}