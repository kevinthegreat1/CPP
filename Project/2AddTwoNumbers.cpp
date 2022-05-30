//
// Created by Kevin Yang on 5/15/21.
//

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *answer = nullptr, *lastNode = nullptr, *tempNode;
        int t, carry = 0;
        while (l1|| l2) {
            t = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            tempNode = new ListNode(t % 10);
            carry = t / 10;
            if (answer == nullptr) {
                answer = tempNode;
                lastNode = answer;
            } else {
                lastNode->next = tempNode;
                lastNode = tempNode;
            }
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        if(carry>0){
            lastNode->next=new ListNode(carry);
        }
        return answer;
    }
};

int main(){
    Solution solution;
    ListNode *answer = solution.addTwoNumbers(new ListNode(2,new ListNode(4, new ListNode(3))),new ListNode(5,new ListNode(6, new ListNode(4))));
    cout<<answer->val<<answer->next->val<<answer->next->next->val;
    return 0;
}