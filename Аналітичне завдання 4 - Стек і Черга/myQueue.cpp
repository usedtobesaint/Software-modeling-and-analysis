#include <iostream>
#include <stack>

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {}

    /** Push element x to the back of queue. */
    void push(int x) {
        inStack.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        // Перекладаємо елементи з inStack в outStack, якщо outStack порожній
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }

        // Видаляємо елемент з початку черги (з outStack)
        int front = outStack.top();
        outStack.pop();
        return front;
    }

    /** Get the front element. */
    int peek() {
        // Аналогічно до pop, але не видаляємо елемент
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }

        // Повертаємо елемент з початку черги (з outStack)
        return outStack.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return inStack.empty() && outStack.empty();
    }

private:
    std::stack<int> inStack;
    std::stack<int> outStack;
};

int main() {
    // Приклад використання
    MyQueue myQueue;
    myQueue.push(1);
    myQueue.push(2);

    std::cout << "peek: " << myQueue.peek() << std::endl; // return 1
    std::cout << "pop: " << myQueue.pop() << std::endl;   // return 1
    std::cout << "empty: " << std::boolalpha << myQueue.empty() << std::endl; // return false

    return 0;
}
