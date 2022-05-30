//
// Created by Kevin Yang on 3/21/21.
//

#include <iostream>
#include <vector>

using namespace std;

int n, amount;
vector<int> values;

int coin(int current, int coins) {
    int i;
    for (i = n - 1; i >= 0; i--) {
        if (current + values[i] < amount) {
            int t = coin(current + values[i], coins + 1);
            if (t > 0) {
                return t;
            }
        }
        if (current + values[i] == amount) {
            return coins + 1;
        }
    }
    return -1;
}

int main(){
    int i, t;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>t;
        values.push_back(t);
    }
    cin>>amount;
    cout<<coin(0,0);
}