#include <iostream>
#include <queue>

class MyStack {
private:
    std::queue<int> q1;
    std::queue<int> q2;

public:
    MyStack() {}

    void push(int x) {
        q1.push(x);

        // Пересуваємо всі елементи з q1 в q2
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
    }

    int pop() {
        if (empty()) {
            return -1;
        }

        int topElement = q1.front();
        q1.pop();

        // Пересуваємо всі елементи з q2 в q1
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }

        return topElement;
    }

    int top() {
        if (empty()) {
            return -1;
        }

        return q1.front();
    }

    bool empty() {
        return q1.empty() && q2.empty();
    }
};

int main() {
    // Приклад використання

    MyStack myStack;
    myStack.push(1);
    myStack.push(2);

    std::cout << "Top: " << myStack.top() << std::endl; // 2
    std::cout << "Pop: " << myStack.pop() << std::endl; // 2
    std::cout << "Empty: " << (myStack.empty() ? "true" : "false") << std::endl; // false

    return 0;
}
