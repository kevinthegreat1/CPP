#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, k, i;
    cin >> n >> k;
    int move1[k + 1], move2[k + 1], cows[n + 1], move[n + 1];
    for (i = 1; i <= k; i++) {
        cin >> move1[i] >> move2[i];
    }
    vector<vector<int>> visited;
    for (i = 0; i <= n; i++) {
        cows[i] = i;
        visited.push_back(vector<int>{i});
    }
    for (i = 1; i <= k; i++) {
        swap(cows[move1[i]], cows[move2[i]]);
        visited[cows[move1[i]]].push_back(move1[i]);
        visited[cows[move2[i]]].push_back(move2[i]);
    }
    for (i = 0; i <= n; i++) {
        move[cows[i]] = i;
    }
    for (i = 1; i <= n; i++) {
        int cur = move[i];
        set<int> visit;
        visit.insert(visited[i].begin(), visited[i].end());
        while (cur!=i) {
            visit.insert(visited[cur].begin(), visited[cur].end());
            cur = move[cur];
        }
        cout << visit.size() << endl;
    }
    return 0;
}