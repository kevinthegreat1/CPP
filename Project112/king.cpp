//
// Created by Kevin Yang on 5/15/21.
//

#include <iostream>
#include <set>

using namespace std;

int main() {
    int m, n, most=0, count=0, merchandise, i;
    cin >> m >> n;
    string judges[n];
    int votes[m+1];
    for (i = 0; i <= m; i++) {
        votes[i] = 0;
    }
    for (i = 0; i < n; i++) {
        cin >> judges[i];
        votes[judges[i][0]-'0']++;
    }
    for(i=1;i<=m;i++){
        most=max(votes[i],most);
    }
    for(i=1;i<=m;i++){
        if(votes[i]==most){
            merchandise=i;
            count++;
        }
    }
    if(count==1){
        cout<<merchandise;
    } else {
        cout<<-(votes[merchandise]);
    }
    return 0;
}