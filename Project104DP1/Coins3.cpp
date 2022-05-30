//
// Created by Kevin Yang on 3/21/21.
//

#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> values;

int coin(int amount) {
    int i;
    vector<int> dp(amount + 1, INFINITY);
    dp[0] = 0;
    for (i = 0; i < dp.size(); i++) {
        for (int coin:values) {
            if (i - coin < 0) {
                continue;
            }
            dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }
    return dp[amount] == INFINITY ? -1 : dp[amount];
}

int main(){
    int amount, i, t;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>t;
        values.push_back(t);
    }
    cin>>amount;
    cout<<coin(amount);
}