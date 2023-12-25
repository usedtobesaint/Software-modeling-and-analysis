#include <iostream>
#include <vector>

class MyCircularQueue {
private:
    std::vector<int> data;
    int front;
    int rear;
    int capacity;
    int size;

public:
    MyCircularQueue(int k) {
        data.resize(k);
        front = 0;
        rear = -1;
        capacity = k;
        size = 0;
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        rear = (rear + 1) % capacity;
        data[rear] = value;
        size++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % capacity;
        size--;
        return true;
    }

    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return data[front];
    }

    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return data[rear];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};

int main() {
    // Приклад використання

    MyCircularQueue myCircularQueue(3);
    std::cout << myCircularQueue.enQueue(1) << std::endl;   // true
    std::cout << myCircularQueue.enQueue(2) << std::endl;   // true
    std::cout << myCircularQueue.enQueue(3) << std::endl;   // true
    std::cout << myCircularQueue.enQueue(4) << std::endl;   // false
    std::cout << myCircularQueue.Rear() << std::endl;       // 3
    std::cout << myCircularQueue.isFull() << std::endl;     // true
    std::cout << myCircularQueue.deQueue() << std::endl;    // true
    std::cout << myCircularQueue.enQueue(4) << std::endl;   // true
    std::cout << myCircularQueue.Rear() << std::endl;       // 4

    return 0;
}
