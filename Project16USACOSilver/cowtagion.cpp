#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, a, i, j;
    cin >> n;
    int paths[n + 1];
    for (i = 1; i <= n; i++) {
        paths[i] = 0;
    }
    for (i = 1; i < n; i++) {
        cin >> a;
        paths[a]++;
        cin >> a;
        paths[a]++;
    }
    for (i = 2; i <= n; i++) {
        paths[i]--;
    }
    for (i = 1, a = 0; i <= n; i++) {
        if (paths[i] > 0) {
            for (j = 1; pow(2, j) <= paths[i]; j++) {}
            a += j;
        }
    }
    cout << a + n - 1;
    return 0;
}