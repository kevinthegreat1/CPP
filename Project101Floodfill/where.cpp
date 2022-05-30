//
// Created by Kevin Yang on 3/5/21.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

string picture[20];

struct pcl{
    int i1, j1, i2, j2;
};

bool is_pcl(int i1, int j1, int i2, int j2) {
    int i, j;
    set<char> colors;
    for (i = i1; i <= i2; i++) {
        for (j = j1; j <= j2; j++) {
            colors.insert(picture[i][j]);
        }
    }
    if (colors.size() != 2) {
        return false;
    }
    bool visited[20][20] = {false};
    int count = 0;
    queue<pair<int, int> > q;
    for (i = i1; i <= i2; i++) {
        for (j = j1; j <= j2; j++) {
            if (!visited[i][j]) {
                q.push(pair<int, int>{i, j});
                visited[i][j] = true;
                while (!q.empty()) {
                    pair<int, int> t = q.front();
                    q.pop();
                    if (t.first < i2 && picture[t.first + 1][t.second] == picture[t.first][t.second] &&
                        !visited[t.first + 1][t.second]) {
                        q.push(pair<int, int>{t.first + 1, t.second});
                        visited[t.first+1][t.second]= true;
                    }
                    if (t.first > i1 && picture[t.first - 1][t.second] == picture[t.first][t.second] &&
                        !visited[t.first - 1][t.second]) {
                        q.push(pair<int, int>{t.first - 1, t.second});
                        visited[t.first-1][t.second]= true;
                    }
                    if (t.second < j2 && picture[t.first][t.second + 1] == picture[t.first][t.second] &&
                        !visited[t.first][t.second + 1]) {
                        q.push(pair<int, int>{t.first, t.second + 1});
                        visited[t.first][t.second+1]= true;
                    }
                    if (t.second > j1 && picture[t.first][t.second - 1] == picture[t.first][t.second] &&
                        !visited[t.first][t.second - 1]) {
                        q.push(pair<int, int>{t.first, t.second - 1});
                        visited[t.first][t.second-1]= true;
                    }
                }
                count++;
            }
        }
    }
    if (count == 3) {
        return true;
    } else {
        return false;
    }
}

int main() {
    ifstream fin ("where.in");
    ofstream fout ("where.out");
    int n, i1, j1, i2, j2;
    fin >> n;
    for (i1 = 0; i1 < n; i1++) {
        fin >> picture[i1];
    }
    vector<pcl> pcls;
    for (i1 = 0; i1 < n; i1++) {
        for (j1 = 0; j1 < n; j1++) {
            for (i2 = 0; i2 < n; i2++) {
                for (j2 = 0; j2 < n; j2++) {
                    if (is_pcl(i1, j1, i2, j2)) {
                        pcls.push_back(pcl{i1, j1, i2, j2});
                    }
                }
            }
        }
    }
    int answer = 0;
    bool flag;
    for (i1 = 0; i1 < pcls.size(); i1++) {
        for (j1 = 0, flag = false; j1 < pcls.size(); j1++) {
            if (i1 != j1 && pcls[i1].i1 >= pcls[j1].i1 && pcls[i1].i2 <= pcls[j1].i2 && pcls[i1].j1 >= pcls[j1].j1 &&
                pcls[i1].j2 <= pcls[j1].j2) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            answer++;
        }
    }
    fout<<answer;
    return 0;
}