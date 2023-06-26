/* Gauss
3x+4y+5z = 2
1x+2y+1z = 0
5x+3y+3z = 3
mxn系数矩阵 A
3  4  5
1  2  1
5  3  3
A * x = b
x = A^(-1)*b
mx(n+1)增广矩阵
3  4  5  2
1  2  1  0
5  3  3  3
通过初等行变换将其变为
1 0 0 x
0 1 0 y
0 0 1 z
*/
#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

const double eps = 1E-6;
const int N = 200;
int n, m;
double a[N][N] = {{0, 4, 5, 2},
                  {1, 2, 1, 0},
                  {5, 3, 3, 3}};;
double x[N];

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int gauss() {
    for (int i = 0; i < n; i++) {
        // double largest = a[i][i];
        int largestRow = i;
        for (int j = i + 1; j < n; j++) {
            if (fabs(a[j][i]) > fabs(a[largestRow][i])) {
                // largest = fabs(a[j][i]);
                largestRow = j;
            }
        }
        if (fabs(a[largestRow][i]) < eps) return 0; // 无解
        if (i != largestRow) {
            for (int j = i; j <= n; j++) {
                swap(a[i][j], a[largestRow][j]);
            }
        }
        for (int j = i + 1; j <= n; j++) {
            a[i][j] /= a[i][i];
        }
        a[i][i] = 1;
        for (int j = 0; j < n; j++) {
            if (j == i) { continue; }
            for (int k = i + 1; k <= n; k++) {
                a[j][k] -= a[i][k] * a[j][i];
            }
            a[j][i] = 0;
        }
    }
    print();
    cout << endl;
    for (int i = 0; i < n; i++) {
        x[i] = a[i][n];
    }
    return 1; // 有解
}

int main() {
    // cin >> n >> m;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++) cin >> a[i][j];
    //     cin >> a[i][m];
    // }
    n = m = 3;
    gauss();
    for (int i = 0; i < n; i++)
        cout << x[i] << (i < n - 1 ? ' ' : '\n');

    double a[N][N] = {{0, 4, 5, 2},
                      {1, 2, 1, 0},
                      {5, 3, 3, 3}};;
    for (int i = 0; i < n; i++) {
        double tmp = -a[i][m];
        for (int j = 0; j < m; j++) {
            tmp += a[i][j] * x[j];
        }
        printf("%lf\n", tmp);
    }
    return 0;
}

//https://www.jianguoyun.com/p/DVx9umUQ59XhCBiQhY8FIAA#
