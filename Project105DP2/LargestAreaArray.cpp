//
// Created by Kevin Yang on 3/28/21.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, count = 1, answer = 0, i, j, t;
    cin >> n;
    vector<int> vector(n);
    for (i = 0; i < n; i++) {
        cin >> t;
        vector[i] = t;
        answer=max(vector[i],answer);
    }
    for (i = 0; i < n; i++, count = 1) {
        for (j = i + 1; j < n; j++) {
            if (vector[j] >= vector[i]) {
                count++;
            } else {
                answer = max(vector[i] * count, answer);
                break;
            }
        }
        answer = max(vector[i] * count, answer);
        for (j = i - 1; j >= 0; j--) {
            if (vector[j] >= vector[i]) {
                count++;
            } else {
                answer = max(vector[i] * count, answer);
                break;
            }
        }
        answer = max(vector[i] * count, answer);
    }
    cout << answer;
    return 0;
}