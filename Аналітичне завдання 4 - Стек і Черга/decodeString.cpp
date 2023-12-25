#include <iostream>
#include <stack>
#include <sstream>

std::string decodeString(const std::string& s) {
    std::stack<int> countStack;
    std::stack<std::string> resultStack;
    std::string currentString;
    int count = 0;

    for (char ch : s) {
        if (isdigit(ch)) {
            count = count * 10 + (ch - '0');
        }
        else if (ch == '[') {
            countStack.push(count);
            resultStack.push(currentString);
            count = 0;
            currentString.clear();
        }
        else if (ch == ']') {
            int repeatCount = countStack.top();
            countStack.pop();

            std::string previousString = resultStack.top();
            resultStack.pop();

            for (int i = 0; i < repeatCount; ++i) {
                previousString += currentString;
            }

            currentString = previousString;
        }
        else {
            currentString += ch;
        }
    }

    return currentString;
}

int main() {
    // Приклади використання

    std::cout << decodeString("3[a]2[bc]") << std::endl;   // "aaabcbc"
    std::cout << decodeString("3[a2[c]]") << std::endl;    // "accaccacc"
    std::cout << decodeString("2[abc]3[cd]ef") << std::endl; // "abcabccdcdcdef"

    return 0;
}
