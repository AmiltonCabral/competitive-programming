#include <bits/stdc++.h>
using namespace std;

class MinStack {
   public:
    list<int> stk;
    int minVal;
    MinStack() {}

    void push(int val) {
        if (stk.empty()) {
            minVal = val;
        } else {
            minVal = min(val, minVal);
        }
        stk.push_back(val);
    }

    void pop() {
        if (stk.back() == minVal) {
            stk.pop_back();
            minVal = stk.back();
            for (int &val : stk) {
                minVal = min(val, minVal);
            }
        } else {
            stk.pop_back();
        }
    }

    int top() { return stk.back(); }

    int getMin() { return minVal; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
