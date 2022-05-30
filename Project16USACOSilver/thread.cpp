#include <iostream>
#include <thread>

using namespace std;

void print(int a) {
    for (int i = 0; i < a; i++) {
        cout << i << endl;
    }
}

int main() {
    thread thread1(print, 100);
    thread thread2(print, 100);
    thread thread3(print, 100);
    thread thread4(print, 100);

    thread1.join();
    thread2.join();
    thread3.join();
    thread4.join();
}