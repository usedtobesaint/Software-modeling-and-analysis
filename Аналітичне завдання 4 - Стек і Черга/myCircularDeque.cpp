#include <iostream>
#include <vector>

class MyCircularDeque {
private:
    std::vector<int> data;
    int front;
    int rear;
    int capacity;

public:
    MyCircularDeque(int k) {
        data.resize(k + 1);
        front = 0;
        rear = 0;
        capacity = k + 1;
    }

    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        front = (front - 1 + capacity) % capacity;
        data[front] = value;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        data[rear] = value;
        rear = (rear + 1) % capacity;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % capacity;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        rear = (rear - 1 + capacity) % capacity;
        return true;
    }

    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return data[front];
    }

    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return data[(rear - 1 + capacity) % capacity];
    }

    bool isEmpty() {
        return front == rear;
    }

    bool isFull() {
        return (rear + 1) % capacity == front;
    }
};

int main() {
    // Приклад використання

    MyCircularDeque myCircularDeque(3);
    std::cout << myCircularDeque.insertLast(1) << std::endl;    // true
    std::cout << myCircularDeque.insertLast(2) << std::endl;    // true
    std::cout << myCircularDeque.insertFront(3) << std::endl;   // true
    std::cout << myCircularDeque.insertFront(4) << std::endl;   // false
    std::cout << myCircularDeque.getRear() << std::endl;        // 2
    std::cout << myCircularDeque.isFull() << std::endl;         // true
    std::cout << myCircularDeque.deleteLast() << std::endl;     // true
    std::cout << myCircularDeque.insertFront(4) << std::endl;   // true
    std::cout << myCircularDeque.getFront() << std::endl;       // 4

    return 0;
}
