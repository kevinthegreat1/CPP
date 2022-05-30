//
// Created by Kevin Yang on 5/28/21.
//

#include <iostream>
#include <vector>

using namespace std;

int main(){
    string s;
    int largest=0, i;
    vector<int> letters(26,0);
    cin>>s;
    for (i = 0; i < s.size(); i++) {
        letters[s[i]-'a']++;
    }
    for(i=0;i<26;i++){
        largest=max(letters[i],largest);
    }
    for(i=0;i<26;i++){
        if(letters[i]==largest){
            cout<<char(i+'a')<<endl<<largest;
            return 0;
        }
    }
    return 0;
}