// Source : https://leetcode.com/problems/min-stack/
// Author : weekend27
// Date   : 2015-12-19

/**********************************************************************************

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.

**********************************************************************************/

// How to do it:
// ref: http://bangbingsyb.blogspot.sg/2014/11/leetcode-min-stack.html

class MinStack {
    stack<int> s;
    stack<int> sMin;
public:
    void push(int x) {
        s.push(x);
        if (sMin.empty() || x <= sMin.top()){
            sMin.push(x);
        }
    }

    void pop() {
        if (s.top() <= sMin.top()){
            sMin.pop();
        }
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return sMin.top();
    }
};
