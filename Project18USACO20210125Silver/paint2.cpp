#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q, a, b, i, j;
    char t;
    string target;
    cin >> n >> q >> target;
    bool visited[n];
    int paint[n];
    for (i = 0; i < n; ++i) {
        visited[i] = false;
    }
    for (i = 1;; i++) {
        for (j = 0; j < n; j++) {
            if (visited[j]) {
                continue;
            }
            t = target[j];
            break;
        }
        for (; j < n; j++) {
            if (t > target[j]) {
                i++;
                for (; j < n; j++) {
                    if (visited[j]) {
                        continue;
                    }
                    t = target[j];
                    break;
                }
            }
            if (visited[j]) {
                continue;
            }
            if (target[j] == t) {
                paint[j] = i;
                visited[j] = true;
            }
        }
        for (j = 0; j < n; j++) {
            if (!visited[j]) {
                break;
            }
        }
        if (j == n) {
            break;
        }
    }
    int total[n];
    total[0] = paint[0];
    for (i = 1; i < n; i++) {
        total[i] = max(total[i - 1], paint[i]);
    }
    for (i = 0; i < q; i++) {
        cin >> a >> b;
    }
    return 0;
}