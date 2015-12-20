// Source : https://leetcode.com/problems/implement-queue-using-stacks/
// Author : weekend27
// Date   : 2015-12-20

/**********************************************************************************

Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
Notes:
You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).

**********************************************************************************/

// How to do it:
/*
只要我们在插入元素的时候每次都都从前面插入即可，比如如果一个队列是1,2,3,4，那么我们在栈中保存为4,3,2,1，那么返回栈顶元素1，也就是队列的首元素，则问题迎刃而解。
所以此题的难度是push函数，我们需要一个辅助栈tmp，把s的元素也逆着顺序存入tmp中，此时加入新元素x，再把tmp中的元素存回来，这样就是我们要的顺序了，其他三个操作也就直接调用栈的操作即可，
*/


class Queue {
private:
    stack<int> s;
public:
    // Push element x to the back of queue.
    void push(int x) {
        stack<int> tmp;
        while (!s.empty()){
            tmp.push(s.top());
            s.pop();
        }
        s.push(x);
        while (!tmp.empty()){
            s.push(tmp.top());
            tmp.pop();
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        s.pop();
    }

    // Get the front element.
    int peek(void) {
        return s.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s.empty();
    }
};
