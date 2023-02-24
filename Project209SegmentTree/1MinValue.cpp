//
// Created by Kevin Yang on 2/9/23.
//

#include <iostream>

using namespace std;

typedef struct Node {
    int leftBound;
    int rightBound;
    int value;
    int lazy;
    Node *left;
    Node *right;

    Node(int l, int r, int v) : leftBound(l), rightBound(r), value(v), lazy(0), left(), right() {}

    static Node *buildTree(int left, int right) {
        if (left == right) {
            return new Node(left, right, 0);
        }
        int mid = (left + right) / 2;
        Node *cur = new Node(left, right, 0);
        cur->left = buildTree(left, mid);
        cur->right = buildTree(mid + 1, right);
        return cur;
    }

    void rangeAdd(int addLeft, int addRight, int addValue) {
        if (addLeft > rightBound || addRight < leftBound) {
            return;
        }
        if (leftBound >= addLeft && rightBound <= addRight) {
            value += addValue;
            lazy += addValue;
        } else {
            left->rangeAdd(addLeft, addRight, addValue);
            right->rangeAdd(addLeft, addRight, addValue);
            value = min(left->value, right->value);
        }
    }

    int rangeQuery(int queryLeft, int queryRight) {
        if (queryLeft > rightBound || queryRight < leftBound) {
            return INT32_MAX;
        }
        if (leftBound >= queryLeft && rightBound <= queryRight) {
            return value;
        } else if (lazy != 0) {
            left->value += lazy;
            left->lazy += lazy;
            right->value += lazy;
            right->lazy += lazy;
            lazy = 0;
        }
        int leftValue = left->rangeQuery(queryLeft, queryRight);
        int rightValue = right->rangeQuery(queryLeft, queryRight);
        return min(leftValue, rightValue);
    }
} Node;

int main() {
    int n, m;
    cin >> n >> m;
    Node *valueTreeRoot = Node::buildTree(1, n);
    for (int i = 0; i < m; i++) {
        string operation;
        int left, right;
        cin >> operation >> left >> right;
        if (operation == "ADD") {
            int value;
            cin >> value;
            valueTreeRoot->rangeAdd(left, right, value);
        } else {
            cout << valueTreeRoot->rangeQuery(left, right) << endl;
        }
    }
    return 0;
}