//
// Created by Kevin Yang on 1/1/22.
//


using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
//private:
//    int k;
//    ListNode *head;
//
//    int dfs(ListNode *node) {
//        if (node->next != nullptr) {
//            int t = dfs(node->next);
//            if (t == 0) {
//                return 0;
//            } else if (t == k) {
//                head = node->next;
//                node->next = nullptr;
//                return 0;
//            } else {
//                return t + 1;
//            }
//        } else {
//            node->next = head; //FIXME heap use after free
//            return 1;
//        }
//    }

public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == nullptr) {
            return head;
        }
//        this->head = head;
//        this->k = k;
//        dfs(head);
//        return this->head;
        ListNode *cur = head;
        int i;
        for (i = 0; cur->next != nullptr; i++) {
            cur = cur->next;
        }
        cur->next = head;
        i++;
        while (k >= i) {
            k -= i;
        }
        k = i - k;
        for (i = 0; i < k; i++) {
            cur = cur->next;
        }
        ListNode *ans = cur->next;
        cur->next = nullptr;
        return ans;
    }
};

int main() {
    Solution solution;
    auto *node5 = new ListNode(5);
    auto *node4 = new ListNode(4, node5);
    auto *node3 = new ListNode(3);
    auto *node2 = new ListNode(2, node3);
    auto *node1 = new ListNode(1, node2);
    auto *a = solution.rotateRight(node1, 4);
    return 0;
}