#include <iostream>

using namespace std;

bool leapyear(int year){
    bool leapyear;
    year=2400;
    if((year%4==0 && year%100!=0) || year%400==0){
        leapyear=true;
    } else {
        leapyear=false;
    }
    return leapyear;
}

int main(){
    cout<<leapyear(2000);
    return 0;
}