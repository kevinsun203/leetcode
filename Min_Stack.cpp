#include "stack";
using namespace std;

class MinStack {
private:
    stack<int> stck;
    //monotonically dec. stack
    stack<pair<int,int>> minDec;
public:
    MinStack() {
    }
    
    void push(int val) {
        stck.push(val);
        if (minDec.empty() || minDec.top().first >= val) {
            if (!minDec.empty() && minDec.top().first == val) {
                minDec.top().second++;
            } else {
                minDec.push({val, 1});
            }
        }
    }
    
    void pop() {
        int temp = stck.top();
        stck.pop();

        if (temp == minDec.top().first) {
            minDec.top().second--;
            if (minDec.top().second == 0) {
                minDec.pop();
            }
        }
    }
    
    int top() {
        return stck.top();
    }
    
    int getMin() {
        return minDec.top().first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */