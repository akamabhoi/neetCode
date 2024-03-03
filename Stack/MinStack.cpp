// Implementation of a stack data structure that supports push, pop, top, and retrieving the minimum element in constant time.

#include <stack>

class MinStack
{
public:
    // Main stack to store elements
    std::stack<int> mainStack;
    // Auxiliary stack to keep track of the minimum element
    std::stack<int> minStack;

    // Constructor
    MinStack() {}

    // Function to push a value onto the stack
    void push(int val)
    {
        // If the minStack is empty or the value is less than or equal to the current minimum, push the value onto minStack
        if (minStack.empty() || val <= minStack.top())
        {
            minStack.push(val);
        }
        // Push the value onto the main stack
        mainStack.push(val);
    }

    // Function to pop the top element from the stack
    void pop()
    {
        // If the main stack is not empty
        if (!mainStack.empty())
        {
            // If the top element of the main stack is equal to the top element of minStack, pop from minStack
            if (mainStack.top() == minStack.top())
            {
                minStack.pop();
            }
            // Pop from the main stack
            mainStack.pop();
        }
    }

    // Function to return the top element of the stack
    int top()
    {
        // If the main stack is not empty, return the top element
        if (!mainStack.empty())
        {
            return mainStack.top();
        }
        // Indicate an error, stack is empty
        return -1;
    }

    // Function to return the minimum element of the stack
    int getMin()
    {
        // If the minStack is not empty, return the top element
        if (!minStack.empty())
        {
            return minStack.top();
        }
        // Indicate an error, stack is empty
        return -1;
    }
};

/**
 * Example usage:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
