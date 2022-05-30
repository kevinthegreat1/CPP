//
// Created by Kevin Yang on 5/23/21.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    int n, k, i;
    cin>>n>>k;
    vector<int> v(n), t(n);
    set<vector<int>> ans;
    for(i=0;i<n;i++){
        cin>>v[i];
    }
    t=v;
    for(i=0;i<=n-k;i++,t=v){
        sort(&t[i],&t[i+k]);
        ans.insert(t);
    }
    cout<<ans.size();
    return 0;
}