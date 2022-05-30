#include <iostream>

using namespace std;

struct Class1 {
    int number;
};


int main(){
    Class1 *class1= new Class1;
    class1->number=1;
    cout<<class1->number<<endl;
    return 0;
}