#include <iostream>
#include <vector>
#include <stack>

// Визначення структури вузла бінарного дерева
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

std::vector<int> inorderTraversal(TreeNode* root) {
    std::vector<int> result;
    std::stack<TreeNode*> nodeStack;

    TreeNode* currentNode = root;

    while (currentNode != nullptr || !nodeStack.empty()) {
        while (currentNode != nullptr) {
            // Додаємо вузол в стек і переходимо до лівого піддерева
            nodeStack.push(currentNode);
            currentNode = currentNode->left;
        }

        // Вибираємо вузол зі стеку та додаємо його значення до результату
        currentNode = nodeStack.top();
        nodeStack.pop();
        result.push_back(currentNode->val);

        // Переходимо до правого піддерева
        currentNode = currentNode->right;
    }

    return result;
}

int main() {
    // Приклади використання

    // Приклад 1
    TreeNode* root1 = new TreeNode(1);
    root1->right = new TreeNode(2);
    root1->right->left = new TreeNode(3);
    std::vector<int> result1 = inorderTraversal(root1);
    for (int value : result1) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    // Приклад 2
    TreeNode* root2 = nullptr;
    std::vector<int> result2 = inorderTraversal(root2);
    for (int value : result2) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    // Приклад 3
    TreeNode* root3 = new TreeNode(1);
    std::vector<int> result3 = inorderTraversal(root3);
    for (int value : result3) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}

