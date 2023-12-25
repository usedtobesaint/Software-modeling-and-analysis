#include <iostream>

using namespace std;

// Визначення структури вузла бінарного дерева
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* invertTree(TreeNode* root) {
    // Базовий випадок: якщо корінь NULL, повертаємо NULL
    if (!root) {
        return NULL;
    }

    // Рекурсивно інвертуємо ліве і праве піддерева
    TreeNode* temp = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(temp);

    return root;
}

// Допоміжна функція для виведення значень вузлів бінарного дерева
void printTree(TreeNode* root) {
    if (!root) {
        return;
    }

    printTree(root->left);
    cout << root->val << " ";
    printTree(root->right);
}

int main() {
    // Створення прикладу бінарного дерева
    TreeNode* example = new TreeNode(4);
    example->left = new TreeNode(2);
    example->right = new TreeNode(7);
    example->left->left = new TreeNode(1);
    example->left->right = new TreeNode(3);
    example->right->left = new TreeNode(6);
    example->right->right = new TreeNode(9);

    // Виведення початкового стану дерева
    cout << "Original Tree: ";
    printTree(example);
    cout << endl;

    // Інвертування дерева
    TreeNode* invertedTree = invertTree(example);

    // Виведення інвертованого дерева
    cout << "Inverted Tree: ";
    printTree(invertedTree);
    cout << endl;

    return 0;
}
