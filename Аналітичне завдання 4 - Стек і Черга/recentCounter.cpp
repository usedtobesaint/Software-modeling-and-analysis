#include <iostream>
#include <queue>

class RecentCounter {
private:
    std::queue<int> q;

public:
    RecentCounter() {}

    int ping(int t) {
        q.push(t);

        // Видаляємо елементи, які виходять за межі діапазону [t - 3000, t]
        while (!q.empty() && q.front() < t - 3000) {
            q.pop();
        }

        return q.size();
    }
};

int main() {
    // Приклад використання

    RecentCounter recentCounter;
    std::cout << recentCounter.ping(1) << std::endl;    // 1
    std::cout << recentCounter.ping(100) << std::endl;  // 2
    std::cout << recentCounter.ping(3001) << std::endl; // 3
    std::cout << recentCounter.ping(3002) << std::endl; // 3

    return 0;
}
