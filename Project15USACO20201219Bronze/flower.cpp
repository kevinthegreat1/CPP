#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, petals, count=0, i, j, k;
    cin >> n;
    int flowers[n];
    for (i = 0; i < n; i++) {
        cin >> flowers[i];
    }
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            for (k = i, petals = 0; k <= j; k++) {
                petals += flowers[k];
            }
            for (k = i; k <= j; k++) {
                if (flowers[k] * (j - i + 1) == petals) {
                    count++;
                    break;
                }
            }
        }
    }
    cout<<count;
    return 0;
}