//
// Created by Kevin Yang on 5/29/21.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, size, count = 0, i, j;
    cin >> n;
    size = 2 * n;
    vector<bool> doors(size, true);
    for (i = 2; i <= n; i++) {
        for (j = 1; j <= size; j++) {
            if (j % i == 0) {
                doors[j - 1].flip();
            }
        }
    }
    for (i = 0; i < size; i++) {
        count += doors[i];
    }
    cout << count;
    return 0;
}