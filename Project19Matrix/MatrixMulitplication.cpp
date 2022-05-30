//
// Created by Kevin Yang on 2/3/21.
//

#include <iostream>
#include <vector>
#include "Matrix.h"

int main() {
    int m, n, p, i, j, k;
    std::vector<int> t;
    Matrix a, b;
    std::cin >> m >> n;
    for (i = 0; i < m; i++) {
        for (j = 0, t.clear(); j < n; j++) {
            std::cin >> k;
            t.push_back(k);
        }
        a.push_back(t);
    }
    std::cin >> p;
    for (i = 0; i < n; i++) {
        for (j = 0, t.clear(); j < p; j++) {
            std::cin >> k;
            t.push_back(k);
        }
        b.push_back(t);
    }
    out(a * b);
    return 0;
}