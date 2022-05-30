#include <iostream>

using namespace std;

int main(){
    int item, volume, row, column;
    cin>>item>>volume;
    int items[item][2], value[item+1][volume+1];
    for(row=0;row<item;row++){
        cin>>items[row][0]>>items[row][1];
    }
    for(row=0;row<volume;row++){
        for(column=0;column<item;column++){
            value[row][column]=0;
        }
    }
    for(column=1;column<volume;column++){
        for(row=1;row<item;row++){
            if(items[row][1]>volume){
                value[row][column]=value[row-1][column];
            } else {
                value[row][column]=max(value[row-1][column],value[row-1][column-items[row][1]]+items[row][0]);
            }
        }
    }
    return 0;
}