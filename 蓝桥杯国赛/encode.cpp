//
// Created by Kevin Yang on 5/29/21.
//

#include <iostream>

using namespace std;

int main(){
    string s;
    cin>>s;
    for (int i = 0; i < s.size(); i++) {
        s[i]+=3;
    }
    cout<<s;
    return 0;
}