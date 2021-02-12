#pragma once

// 155. Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// Solution: (complexity O(1))
// Whenever we push an item that's smaller than current min, we push current min
// onto the stack before it, and replace current min with new item.
// On pop we check whether we're currently popping the min element, and if we are
// we pop one more item off the stack, that item being the old min value.

SOLUTION_FOR_PROBLEM(155, "Min Stack") {

class MinStack {
public:
    void push(int x) {
        if (x <= m_min) {
            m_stack.push(m_min);
            m_min = x;
        }

        m_stack.push(x);
    }

    void pop() {
        if (m_stack.top() == m_min) {
            m_stack.pop();
            m_min = m_stack.top();
        }

        m_stack.pop();
    }

    int top() {
        return m_stack.top();
    }

    int getMin() {
        return m_min;
    }

private:
    std::stack<int> m_stack;
    int m_min = INT_MAX;
};

SOLVE()
{
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    minStack.getMin(); // return -3
    minStack.pop();
    minStack.top();    // return 0
    minStack.getMin(); // return -2
}

}
