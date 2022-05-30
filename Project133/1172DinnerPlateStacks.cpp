//
// Created by Kevin Yang on 3/13/22.
//

#include <iostream>
#include <vector>
#include <set>
#include <stack>

using namespace std;

class DinnerPlates {
private:
    vector<stack<int>> dinnerPlates;
    int capacity;
    set<int> notFullIndecies;

public:
    explicit DinnerPlates(int capacity) {
        this->capacity = capacity;
        this->dinnerPlates.emplace_back();
    }

    void push(int val) {
        if (notFullIndecies.empty()) {
            if (dinnerPlates.back().size() == capacity) {
                dinnerPlates.emplace_back();
            }
            dinnerPlates.back().push(val);
        } else {
            auto it = notFullIndecies.begin();
            dinnerPlates[*it].push(val);
            if (dinnerPlates[*it].size() == capacity) {
                notFullIndecies.erase(it);
            }
        }
    }

    int pop() {
        if (dinnerPlates.back().empty()) {
            if (dinnerPlates.size() == 1) {
                return -1;
            }
            dinnerPlates.pop_back();
            if (!notFullIndecies.empty()) {
                auto it = --notFullIndecies.end();
                if (*it == dinnerPlates.size()) {
                    notFullIndecies.erase(it);
                }
            }
            return pop();
        }
        int top = dinnerPlates.back().top();
        dinnerPlates.back().pop();
        return top;
    }

    int popAtStack(int index) {
        if (index >= dinnerPlates.size()) {
            return -1;
        }
        if (dinnerPlates[index].empty()) {
            return -1;
        }
        int top = dinnerPlates[index].top();
        dinnerPlates[index].pop();
        notFullIndecies.insert(index);
        return top;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */

int main() {
    /*DinnerPlates dinnerPlates = DinnerPlates(2);
    dinnerPlates.push(1);
    dinnerPlates.push(2);
    dinnerPlates.push(3);
    dinnerPlates.push(4);
    dinnerPlates.push(5);
    cout << dinnerPlates.popAtStack(0) << endl;
    dinnerPlates.push(20);
    dinnerPlates.push(21);
    cout << dinnerPlates.popAtStack(0) << endl;
    cout << dinnerPlates.popAtStack(2) << endl;
    cout << dinnerPlates.pop() << endl;
    cout << dinnerPlates.pop() << endl;
    cout << dinnerPlates.pop() << endl;
    cout << dinnerPlates.pop() << endl;
    cout << dinnerPlates.pop() << endl;*/

    /*["DinnerPlates","push","push","popAtStack","pop","push","push","pop","pop"]
    [[1],[1],[2],[1],[],[1],[2],[],[]]*/

    DinnerPlates dinnerPlates = DinnerPlates(1);
    dinnerPlates.push(1);
    dinnerPlates.push(2);
    cout << dinnerPlates.popAtStack(1) << endl;
    cout << dinnerPlates.pop() << endl;
    dinnerPlates.push(1);
    dinnerPlates.push(2);
    cout << dinnerPlates.pop() << endl;
    cout << dinnerPlates.pop() << endl;
    return 0;
}