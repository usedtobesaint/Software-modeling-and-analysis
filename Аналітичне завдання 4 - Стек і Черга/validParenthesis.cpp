#include <iostream>
#include <stack>
#include <unordered_map>

bool isValid(std::string s) {
    std::stack<char> parenthesesStack;
    std::unordered_map<char, char> parenthesesMap = { {')', '('}, {']', '['}, {'}', '{'} };

    for (char c : s) {
        if (parenthesesMap.find(c) != parenthesesMap.end()) {
            // Якщо це закрита дужка
            char topElement = parenthesesStack.empty() ? '#' : parenthesesStack.top();
            parenthesesStack.pop();

            if (topElement != parenthesesMap[c]) {
                return false;
            }
        }
        else {
            // Якщо це відкрита дужка, додаємо її до стеку
            parenthesesStack.push(c);
        }
    }

    // Перевіряємо, чи стек пустий (всі відкриті дужки мають свої закриті)
    return parenthesesStack.empty();
}

int main() {
    // Приклади використання
    std::cout << std::boolalpha; // Для виведення true/false замість 1/0

    std::cout << isValid("()") << std::endl;       // true
    std::cout << isValid("()[](}") << std::endl;   // false
    std::cout << isValid("(]") << std::endl;       // false

    return 0;
}
