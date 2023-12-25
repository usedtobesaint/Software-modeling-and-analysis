#include <iostream>
#include <vector>
#include <stack>
#include <sstream>

int evalRPN(const std::vector<std::string>& tokens) {
    std::stack<int> numbers;

    for (const std::string& token : tokens) {
        if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-' && isdigit(token[1]))) {
            // Якщо токен є числом, додаємо його до стеку
            numbers.push(std::stoi(token));
        }
        else {
            // Якщо токен є оператором, виконуємо відповідну операцію
            int operand2 = numbers.top();
            numbers.pop();
            int operand1 = numbers.top();
            numbers.pop();

            if (token == "+") {
                numbers.push(operand1 + operand2);
            }
            else if (token == "-") {
                numbers.push(operand1 - operand2);
            }
            else if (token == "*") {
                numbers.push(operand1 * operand2);
            }
            else if (token == "/") {
                numbers.push(operand1 / operand2);
            }
        }
    }

    // Результат знаходиться на вершині стеку
    return numbers.top();
}

int main() {
    // Приклади використання

    std::vector<std::string> tokens1 = { "2","1","+","3","*" };
    std::cout << "Output 1: " << evalRPN(tokens1) << std::endl; // 9

    std::vector<std::string> tokens2 = { "4","13","5","/","+" };
    std::cout << "Output 2: " << evalRPN(tokens2) << std::endl; // 6

    std::vector<std::string> tokens3 = { "10","6","9","3","+","-11","*","/","*","17","+","5","+" };
    std::cout << "Output 3: " << evalRPN(tokens3) << std::endl; // 22

    return 0;
}
