#include <iostream>

using namespace std;

void ConsecutiveIntegers() {
    int n, i, j, sum, k;
    cout << "Consecutive integers with this sum: ";
    cin >> n;
    for (i = 1; i <= (n / 2); i++) {
        for (j = i, sum = 0; sum < n; j++) {
            sum += j;
            if (sum == n) {
                for (k = i; k <= j; k++) {
                    cout << k;
                    if (k < j) {
                        cout << ", ";
                    }
                }
                cout << endl;
            }
        }
    }
}

void LongSideOfRightTriangles() {
    int a, b;
    cout << "Long side of right triangles with two sides: ";
    cin >> a >> b;
    cout << sqrt(pow(a, 2) + pow(b, 2));
}

void SumOfFloorsOfSquareRootsOfConsecutiveIntegers() {
    int n, i, sum = 0;
    cout << "Sum of floors of square roots of consecutive integers; From 1 to this number: ";
    cin >> n;
    for (i = 1; i <= n; i++) {
        sum += floor(sqrt(i));
    }
    cout << sum;
}

void PerfectSquaresSmallerOrEqualsTo() {
    int n, a, i;
    cout << "Perfect squares smaller or equals to this number: ";
    cin >> n;
    a = floor(sqrt(n));
    for (i = 1; i <= a; i++) {
        cout << pow(i, 2);
        if (i < a) {
            cout << ", ";
        }
    }
}

int main() {
    ConsecutiveIntegers();
}