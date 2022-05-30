#include <iostream>
#include <vector>

using namespace std;

vector<int> HappySequence;

void HappyNumber(int n) {
    int i, next = 0;
    for (i = 0; n != 0; i++) {
        next += pow(n % 10, 2);
        n /= 10;
    }
    HappySequence.push_back(next);
    cout << next;
    if (next != 1 && find(HappySequence.begin(), HappySequence.end(), next) ==
                     HappySequence.end() - 1) { //end - 1 is itself which was put in there two lines ago
        cout << ", ";
        HappyNumber(next);
    }
}

int main() {
    int n, i;
    cin>>n;
    HappyNumber(n);
    return 0;
}