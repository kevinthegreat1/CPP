//
// Created by Kevin Yang on 12/29/22.
//

#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

const int N = 100001;
int n;
int q;

typedef struct Operation {
    bool type;
    int start;
    int end;
} Operation;

typedef struct BinaryIndexTree {
    int tree[N];

    static int leastSignificantOneBit(int index) {
        return index & (-index);
    }

    int prefixSum(int index) {
        int sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= leastSignificantOneBit(index);
        }
        return sum;
    }

    void add(int index, int value) {
        if (index > 0) {
            while (index <= n) {
                tree[index] += value;
                index += leastSignificantOneBit(index);
            }
        }
    }
} BinaryIndexTree;

int main() {
    cin >> n >> q;
    int a[n + 1];
    int b[n + 1];
    int c[n + 1];
    BinaryIndexTree bit;
    Operation operation;
    memset(a, 0, sizeof(a));
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        bit.tree[i] = 0;
    }
    for (int i = 0; i < q; i++) {
        string type;
        cin >> type;
        operation.type = type == "add";
        cin >> operation.start >> operation.end;
        if (operation.type) {
            for (int j = operation.start; j <= operation.end; j++) {
                a[j]++;
                int difference = (int) floor(a[j] / b[j]) - c[j];
                c[j] += difference;
                bit.add(j, difference);
            }
        } else {
            cout << bit.prefixSum(operation.end) - bit.prefixSum(operation.start - 1) << endl;
        }
    }
}