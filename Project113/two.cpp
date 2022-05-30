//
// Created by Kevin Yang on 5/23/21.
//

#include <iostream>

using namespace std;

int main() {
    int n, i, j;
    cin >> n;
    for (i = 0; i < n; i++) {
        cout << '*';
    }
    cout << endl;
    for (i = n - 2; i > 0; i--) {
        for (j = 0; j < i; j++) {
            cout << ' ';
        }
        cout << '*' << endl;
    }
    for (i = 0; i < n; i++) {
        cout << '*';
    }
    return 0;
}