//
// Created by Kevin Yang on 2/9/23.
//

#include <iostream>

using namespace std;

int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int gcd2(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

typedef struct Node {
    int leftBound;
    int rightBound;
    int value;
    int lazy;
    Node *left;
    Node *right;

    Node(int l, int r, int v) : leftBound(l), rightBound(r), value(v), lazy(0), left(), right() {}

    virtual int operation(int a, int b) = 0;

    bool hasOverlap(int checkLeft, int checkRight) {
        return checkLeft <= rightBound && checkRight >= leftBound;
    }

    void add(int addIndex, int addValue) {
        rangeAdd(addIndex, addIndex, addValue);
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
            value = operation(left->value, right->value);
        }
    }

    int query(int queryIndex) {
        return rangeQuery(queryIndex, queryIndex);
    }

    int rangeQuery(int queryLeft, int queryRight) {
        if (leftBound >= queryLeft && rightBound <= queryRight) {
            return value;
        } else if (lazy != 0) {
            left->value += lazy;
            left->lazy += lazy;
            right->value += lazy;
            right->lazy += lazy;
            lazy = 0;
        }
        bool leftInRange = left->hasOverlap(queryLeft, queryRight);
        bool rightInRange = right->hasOverlap(queryLeft, queryRight);
        if (leftInRange && rightInRange) {
            return operation(left->rangeQuery(queryLeft, queryRight), right->rangeQuery(queryLeft, queryRight));
        } else if (leftInRange) {
            return left->rangeQuery(queryLeft, queryRight);
        } else if (rightInRange) {
            return right->rangeQuery(queryLeft, queryRight);
        }
        return 0;
    }
} Node;

typedef struct SumNode : Node {
    SumNode(int l, int r, int v) : Node(l, r, v) {}

    static SumNode *buildTree(int left, int right) {
        if (left == right) {
            return new SumNode(left, right, 0);
        }
        int mid = (left + right) / 2;
        SumNode *cur = new SumNode(left, right, 0);
        cur->left = buildTree(left, mid);
        cur->right = buildTree(mid + 1, right);
        return cur;
    }

    int operation(int a, int b) override {
        return a + b;
    }
} SumNode;

typedef struct GCDNode : Node {
    GCDNode(int l, int r, int v) : Node(l, r, v) {}

    static GCDNode *buildTree(int left, int right) {
        if (left == right) {
            return new GCDNode(left, right, 0);
        }
        int mid = (left + right) / 2;
        GCDNode *cur = new GCDNode(left, right, 0);
        cur->left = buildTree(left, mid);
        cur->right = buildTree(mid + 1, right);
        return cur;
    }

    int operation(int a, int b) override {
        return gcd(a, b);
    }
} GCDNode;

int main() {
    int n, m;
    cin >> n >> m;
    SumNode *valueTreeRoot = SumNode::buildTree(1, n);
    GCDNode *differenceTreeRoot = GCDNode::buildTree(1, n);
    for (int i = 0; i < m; i++) {
        string operation;
        int left, right;
        cin >> operation >> left >> right;
        if (operation == "ADD") {
            int value;
            cin >> value;
            valueTreeRoot->rangeAdd(left, right, value);
            differenceTreeRoot->add(left, value);
            differenceTreeRoot->add(right + 1, -value);
        } else {
            cout << gcd(valueTreeRoot->query(left), differenceTreeRoot->rangeQuery(left + 1, right)) << endl;
        }
    }
    return 0;
}