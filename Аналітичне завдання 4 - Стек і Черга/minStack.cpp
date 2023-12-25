#include <iostream>
#include <stack>

class MinStack {
public:
    MinStack() {}

    void push(int val) {
        dataStack.push(val);

        // Додаємо мінімальний елемент до стеку мінімумів або вибираємо менший елемент
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    void pop() {
        // Перевіряємо, чи поточний елемент є мінімальним перед видаленням
        if (dataStack.top() == minStack.top()) {
            minStack.pop();
        }

        dataStack.pop();
    }

    int top() {
        return dataStack.top();
    }

    int getMin() {
        return minStack.top();
    }

private:
    std::stack<int> dataStack;
    std::stack<int> minStack;
};

int main() {
    // Приклад використання
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);

    std::cout << "getMin: " << minStack.getMin() << std::endl; // return -3

    minStack.pop();
    std::cout << "top: " << minStack.top() << std::endl; // return 0

    std::cout << "getMin: " << minStack.getMin() << std::endl; // return -2

    return 0;
}
