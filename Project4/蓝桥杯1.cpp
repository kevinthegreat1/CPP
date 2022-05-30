#include <iostream>

using namespace std;

int main(){
    int month, day;
    cin>>month>>day;
    if(month<2 && day<25){
        cout<<"Pig";
    } else {
        cout<<"Mouse";
    }
    return 0;
}