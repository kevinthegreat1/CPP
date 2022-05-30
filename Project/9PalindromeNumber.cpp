//
// Created by Kevin Yang on 5/8/21.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x == 0) {
            return true;
        }
        if (x % 10 == 0 || x < 0) {
            return false;
        }
        int rev = 0, t = x;
        while (t != 0) {
            if (rev < INT_MIN / 10 || rev > INT_MAX / 10) {
                return false;
            }
            rev = (rev * 10) + (t % 10);
            t /= 10;
        }
        if (rev == x) {
            return true;
        }
        return false;
    }
};

int main(){
    Solution solution;
    cout<<solution.isPalindrome(0);
    return 0;
}