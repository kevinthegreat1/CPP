#include <iostream>
#include <vector>

using namespace std;

int paint(string target) {
    if (target.empty()) {
        return 0;
    } else if (target.size() == 1) {
        return 1;
    }
    int minimum = 999, i, ans = 1;
    vector<int> vector;
    for (i = 0; i < target.size(); i++) {
        minimum = min(minimum, (int) target[i]);
    }
    for (i = 0; i < target.size(); i++) {
        if (minimum == (int) target[i]) {
            vector.push_back(i);
        }
    }
    if (vector[0] > 0) {
        ans += paint(target.substr(0, vector[0]));
    }
    for (i = 0; i < vector.size() - 1; i++) {
        ans += paint(target.substr(vector[i] + 1, vector[i + 1] - vector[i] - 1));
    }
    if (vector[i] < target.size() - 1) {
        ans += paint(target.substr(vector[i] + 1, target.size() - vector[i] - 1));
    }
    return ans;
}

int main() {
    int n, q, a, b, i;
    string target;
    cin >> n >> q >> target;
    for (i = 0; i < q; i++) {
        cin >> a >> b;
        cout<<paint(target.substr(0,a-1))+paint(target.substr(b,n-1))<<endl;
    }
    return 0;
}