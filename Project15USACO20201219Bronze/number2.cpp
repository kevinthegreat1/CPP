#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int a, i;
    vector<int> numbers;
    for (i = 0; i < 7; i++) {
        cin >> a;
        numbers.push_back(a);
    }
    sort(numbers.begin(),numbers.end());
    cout<<numbers[0]<<" "<<numbers[1]<<" ";
    if(numbers[0]+numbers[1]+numbers[2]==numbers[6]){
        cout<<numbers[2];
    } else {
        cout<<numbers[3];
    }
    return 0;
}