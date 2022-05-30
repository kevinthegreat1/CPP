#include <fstream>

using namespace std;

int main() {
    ifstream fin("planting.in");
    ofstream fout("planting.out");
    int n, a, i;
    fin >> n;
    int paths[n + 1];
    for (i = 1; i <= n; i++) {
        paths[i] = 0;
    }
    for (i = 1; i < n; i++) {
        fin >> a;
        paths[a]++;
        fin >> a;
        paths[a]++;
    }
    for (i = 2; i <= n; i++) {
        paths[i]--;
    }
    for (i = 2, a = 1; i <= n; i++) {
        if (paths[i] >= paths[a]) {
            a = i;
        }
    }
    if (a == 1) {
        fout << paths[a] + 1;
    } else {
        fout << paths[a] + 2;
    }
    return 0;
}