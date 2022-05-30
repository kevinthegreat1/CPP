//
// Created by Kevin Yang on 5/1/21.
//

#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n, depth=1, i, t;
    cin>>n;
    queue<int> queue;
    for(i=0;i<n;i++){
        cin>>t;
        queue.push(t);
    }
    for(i=0;!queue.empty();i++){
        if(queue.front()==-1){
            cout<<depth;
            return 0;
        }
        queue.pop();
        if(i==0||i==2||i==6||i==14||i==30||i==62){
            depth++;
        }
    }
    return 0;
}