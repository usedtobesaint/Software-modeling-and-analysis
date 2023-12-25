#include <iostream>
#include <stack>

int longestValidParentheses(const std::string& s) {
    int maxLength = 0;
    std::stack<int> indexStack;

    // Додаємо початковий індекс до стеку
    indexStack.push(-1);

    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(') {
            // Додаємо індекс лівої дужки до стеку
            indexStack.push(i);
        }
        else {
            // Забираємо останній елемент із стеку
            indexStack.pop();

            if (!indexStack.empty()) {
                // Якщо стек не порожній, визначаємо довжину поточної правильно сформованої дужкової послідовності
                maxLength = std::max(maxLength, i - indexStack.top());
            }
            else {
                // Якщо стек порожній, додаємо поточний індекс
                indexStack.push(i);
            }
        }
    }

    return maxLength;
}

int main() {
    // Приклади використання

    std::cout << longestValidParentheses("(()") << std::endl;   // 2
    std::cout << longestValidParentheses(")()())") << std::endl; // 4
    std::cout << longestValidParentheses("") << std::endl;       // 0

    return 0;
}
