#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    deque<int> window;

    for (int i = 0; i < nums.size(); ++i) {
        // Видаляємо з дека елементи, які вже не входять у поточне вікно
        while (!window.empty() && window.front() < i - k + 1) {
            window.pop_front();
        }

        // Видаляємо з дека елементи, які менші за поточний елемент nums[i]
        while (!window.empty() && nums[i] > nums[window.back()]) {
            window.pop_back();
        }

        // Додаємо поточний індекс до дека
        window.push_back(i);

        // Додаємо максимум у поточному вікні до результатів
        if (i >= k - 1) {
            result.push_back(nums[window.front()]);
        }
    }

    return result;
}

int main() {
    // Example 1
    vector<int> nums1 = { 1, 3, -1, -3, 5, 3, 6, 7 };
    int k1 = 3;
    vector<int> result1 = maxSlidingWindow(nums1, k1);

    cout << "Example 1 Result: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    // Example 2
    vector<int> nums2 = { 1 };
    int k2 = 1;
    vector<int> result2 = maxSlidingWindow(nums2, k2);

    cout << "Example 2 Result: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
