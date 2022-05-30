#include <iostream>
#include <string>
#include <random>

using namespace std;

string randomString(int max, bool upper) {
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<> randomLength(1, max);
    int length = randomLength(mt);
    string randomString;
    uniform_int_distribution<> randomChar(0, 25);
    if(upper) {
        for (int i = 0; i < length; i++) {
            randomString += (char) (randomChar(mt) + 65);
        }
    } else {
        for (int i = 0; i < length; i++) {
            randomString += (char) (randomChar(mt) + 97);
        }
    }
    return randomString;
}

int main() {
    while (true) {
        string a;
        cin>>a;
        if(a=="stop"){
            break;
        }
        cout<<randomString(stoi(a), false);
    }
}