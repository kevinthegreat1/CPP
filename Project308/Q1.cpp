/*
3 1 4
1 2 3 4
1 4 2
2 4 2
3 4 4
4 1 4
Output:
6

Input:
4 1 4
5 5 5 5 1
1 5 1
2 5 1
3 5 1
4 5 1
Output:
5
*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int N = 1010;
const int M = 65;
int n,m,p,dp[N][M];
bool vis[N];
typedef struct edge{
    int v, cost;
    edge(int v, int cost):v(v),cost(cost){}
}edge;
vector<edge> edges[N];
void insert_edge(int a, int b, int c){
    edges[a].push_back(edge(b, c));
    edges[b].push_back(edge(a, c));
}
inline void update(int &a,int x){
    a=(a>x || a==-1)? x : a;
}
int solve(){
    memset(dp, -1, sizeof(dp));
    for(int i=0;i<=n;i++){
        dp[i][1<<i] = 0;
    }
    int all = 1<<(n+1);
    for(int j=1;j<all;j++){
        queue<int> Q;
        memset(vis, 0, sizeof(vis));
        for(int i=0;i<=n+m;i++){
            if(i<=n && (j&(1<<i))==0) continue;
            for(int k=(j-1)&j;k;k=(k-1)&j)
            {
                int x=k,y=(j-k);
                if(i<=n) x|=1<<i;
                if(i<=n) y|=1<<i;
                if(dp[i][x]!=-1 && dp[i][y]!=-1)
                    update(dp[i][j],dp[i][x]+dp[i][y]);
            }
            if(dp[i][j] != -1){
                Q.push(i);
                vis[i] = true;
            }
        }
        while(!Q.empty()){
            int u = Q.front(); Q.pop();
            vis[u] = false;
            for(edge e:edges[u]){
                int v = e.v;
                int k = v<=n?(1<<v):0;
                if(dp[v][k|j]==-1 || dp[v][k|j]>dp[u][j]+e.cost)
                {
                    dp[v][k|j]=dp[u][j]+e.cost;
                    if(k|j!=j || vis[v])continue;
                    vis[v]=true;
                    Q.push(v);
                }
            }
        }
    }
    return dp[0][all-1];
}

int main() {
    while(scanf("%d%d%d", &n, &m, &p)!=EOF){
        // cin >> n >> m >> p;
        for(int i=0;i<=n+m;i++) edges[i].clear();
        for (int i = 1; i <= n + m; i++) {
            int cost;
            cin >> cost;
            insert_edge(0, i, cost);
        }
        for (int i = 0; i < p; i++) {
            int from, to, cost;
            cin >> from >> to >> cost;
            insert_edge(from, to, cost);
        }
        cout << solve() << endl;
    }
    return 0;
}