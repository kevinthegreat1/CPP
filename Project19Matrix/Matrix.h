//
// Created by Kevin Yang on 2/3/21.
//

#ifndef C___MATRIX_H
#define C___MATRIX_H
#include <vector>

typedef std::vector<std::vector<int>> Matrix;

Matrix operator * (Matrix a, Matrix b) {
    int m, n, p, ans, i, j, k;
    std::vector<int> t;
    Matrix c;
    m = a.size();
    n = a[0].size();
    p = b[0].size();
    for (i = 0; i < m; i++) {
        for (k = 0, t.clear(); k < p; k++) {
            for (j = 0, ans = 0; j < n; j++) {
                ans += (a[i][j] * b[j][k]);
            }
            t.push_back(ans);
        }
        c.push_back(t);
    }
    return c;
}

Matrix in(){

}
void out(Matrix a) {
    int i, j, m = a.size(), n = a[0].size();
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            std::cout << a[i][j];
            if (j < n - 1) {
                std::cout << ", ";
            }
        }
        if (i < m - 1) {
            std::cout << std::endl;
        }
    }
}

#endif //C___MATRIX_H
