//
// Created by Kevin Yang on 2/13/22.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int strongPasswordChecker(string password) {
        char n = (char) password.size(), digitSteps = 0, repeatingChangeSteps = 0;
        vector<char> repeats;
        bool lowercase = false, uppercase = false, digit = false;
        char cur = 0, count = 0;
        for (char &c: password) {
            if ('a' <= c && c <= 'z') {
                lowercase = true;
            } else if ('A' <= c && c <= 'Z') {
                uppercase = true;
            } else if ('0' <= c && c <= '9') {
                digit = true;
            }
            if (c == cur) {
                count++;
            } else {
                cur = c;
                if (count >= 3) {
                    repeats.push_back(count);
                }
                count = 1;
            }
        }
        if (count >= 3) {
            repeats.push_back(count);
        }
        if (!lowercase) {
            digitSteps++;
        }
        if (!uppercase) {
            digitSteps++;
        }
        if (!digit) {
            digitSteps++;
        }
        if (n < 6) {
            return max(digitSteps, (char) (6 - n));
        } else if (n > 20) {
            char lengthSteps = (char) (n - 20);
            for (char &repeat: repeats) {
                if (repeat % 3 == 0 && lengthSteps > 0) {
                    repeat--;
                    lengthSteps--;
                }
            }
            for (char &repeat: repeats) {
                if (repeat % 3 == 1 && lengthSteps > 1) {
                    repeat -= 2;
                    lengthSteps -= 2;
                }
            }
            for (char &repeat: repeats) {
                while (repeat > 3 && lengthSteps > 2) {
                    repeat -= 3;
                    lengthSteps -= 3;
                }
                if (lengthSteps < 3 && lengthSteps > 0) {
                    repeat -= lengthSteps;
                    lengthSteps = 0;
                }
            }
            for (char &repeat: repeats) {
                repeatingChangeSteps += repeat / 3;
            }
            return n - 20 + max(repeatingChangeSteps, digitSteps);
        } else {
            for (char &repeat: repeats) {
                repeatingChangeSteps += repeat / 3;
            }
            return max(digitSteps, repeatingChangeSteps);
        }
    }
};

int main() {
    Solution solution;
    string s1 = "aaa111"; //2
    string s2 = "ABABABABABABABABABAB1"; //2
    string s3 = "bbaaaaaaaaaaaaaaacccccc"; //8
    string s4 = "FFFFFFFFFFFFFFF11111111111111111111AAA"; //23
    string s5 = "..................!!!"; //7 test 47
    string s6 = "aaaaabbbb1234567890ABA"; //3 test 49
    cout << (solution.strongPasswordChecker(s1) == 2 ? "pass" : "fail") << endl;
    cout << (solution.strongPasswordChecker(s2) == 2 ? "pass" : "fail") << endl;
    cout << (solution.strongPasswordChecker(s3) == 8 ? "pass" : "fail") << endl;
    cout << (solution.strongPasswordChecker(s4) == 23 ? "pass" : "fail") << endl;
    cout << (solution.strongPasswordChecker(s5) == 7 ? "pass" : "fail") << endl;
    cout << (solution.strongPasswordChecker(s6) == 3 ? "pass" : "fail") << endl;
}