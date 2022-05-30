//
// Created by Kevin Yang on 2/11/21.
//

#include <iostream>

using namespace std;

int main() {
    int n, even=0, odd=0, i, t;
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> t;
        if (t % 2 == 0) {
            even++;
        } else {
            odd++;
        }
    }
    if(even==odd || even==odd+1){
        cout<<even+odd;
        return 0;
    } else if(even>odd+1){
        cout<<2*odd+1;
        return 0;
    } else {
        while(even<odd){
            odd-=2;
            even++;
        }
        if(even==odd || even==odd+1){
            cout<<even+odd;
            return 0;
        } else if(even>odd+1){
            cout<<2*odd+1;
            return 0;
        }
        return 0;
    }
}