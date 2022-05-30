//
// Created by Kevin Yang on 2/11/21.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int groups=0, n, i, t;
    cin >> n;
    vector<int> even, odd;
    for (i = 0; i < n; ++i) {
        cin >> t;
        if (t % 2 == 0) {
            even.push_back(t);
        } else {
            odd.push_back(t);
        }
    }
    if (odd.empty()) {
        cout << groups+1;
        return 0;
    }
    if (even.empty()) {
        if(odd.size()%3==0){
            cout<<groups+odd.size()/3*2;
            return 0;
        } else if(odd.size()%3==1){
            cout<<groups+odd.size()/3*2-1;
            return 0;
        } else if(odd.size()%3==2){
            cout<<groups+odd.size()/3*2+1;
        }
        return 0;
    }
    return 0;
}