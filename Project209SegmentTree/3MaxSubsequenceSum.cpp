//
// Created by Kevin Yang on 2/9/23.
//


#include <iostream>

using namespace std;

typedef struct Node {
    int leftBound;
    int rightBound;
    int lazy;
    int largestSum;
    int largestFrontSum;
    int largestBackSum;
    int totalSum;
    Node *left;
    Node *right;

    Node(int l, int r, int v) : leftBound(l), rightBound(r), lazy(0), left(), right() {}

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

    bool isInRange(int index) {
        return index >= leftBound && index <= rightBound;
    }

    bool hasOverlap(int checkLeft, int checkRight) {
        return checkLeft <= rightBound && checkRight >= leftBound;
    }

    void add(int addIndex, int addValue) {
        if (rightBound == leftBound) {
            largestSum += addValue;
            largestFrontSum = largestSum;
            largestBackSum = largestSum;
            totalSum = largestSum;
            return;
        }
        if (left->isInRange(addIndex) && right->isInRange(addIndex)) {
            left->add(addIndex, addValue);
            right->add(addIndex, addValue);
        } else if (left->isInRange(addIndex)) {
            left->add(addIndex, addValue);
        } else if (right->isInRange(addIndex)) {
            right->add(addIndex, addValue);
        }
        largestSum = max(max(left->largestSum, right->largestSum), left->largestBackSum + right->largestFrontSum);
        largestFrontSum = max(left->largestFrontSum, left->totalSum + right->largestFrontSum);
        largestBackSum = max(right->largestBackSum, right->totalSum + left->largestBackSum);
        totalSum = left->totalSum + right->totalSum;
    }

    int rangeQuery(int queryLeft, int queryRight) {
        if (leftBound >= queryLeft && rightBound <= queryRight) {
            return largestSum;
        }
        if (rightBound == leftBound) {
            return largestSum;
        }
        bool leftHasOverlap = left->hasOverlap(queryLeft, queryRight);
        bool rightHasOverlap = right->hasOverlap(queryLeft, queryRight);
        if (leftHasOverlap && rightHasOverlap) {
            return max(left->rangeQuery(queryLeft, queryRight), right->rangeQuery(queryLeft, queryRight));
        } else if (leftHasOverlap) {
            return left->rangeQuery(queryLeft, queryRight);
        } else if (rightHasOverlap) {
            return right->rangeQuery(queryLeft, queryRight);
        }
        return 0;
    }
} Node;

int main() {
    int n, m;
    cin >> n >> m;
    Node *root = Node::buildTree(1, n);
    for (int i = 0; i < m; i++) {
        string operation;
        int left, second;
        cin >> operation >> left >> second;
        if (operation == "ADD") {
            root->add(left, second);
        } else {
            cout << root->rangeQuery(left, second) << endl;
        }
    }
    return 0;
}