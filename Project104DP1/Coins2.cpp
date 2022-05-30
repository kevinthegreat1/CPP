//
// Created by Kevin Yang on 3/21/21.
//

#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> values;

int coin(int amount) {
    int i, minimum = INFINITY;
    if (amount < 0) {
        return -1;
    }
    if (amount == 0) {
        return 0;
    }
    for (i = n - 1; i >= 0; i--) {
        int c = coin(amount - values[i]) + 1;
        if (c <= 0) {
            continue;
        }
        minimum = min(c, minimum);
    }
    return minimum;
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