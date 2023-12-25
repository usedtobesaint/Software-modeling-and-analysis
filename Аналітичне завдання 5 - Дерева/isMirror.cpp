#include <iostream>

using namespace std;

// Визначення структури вузла бінарного дерева
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isMirror(TreeNode* p, TreeNode* q) {
    // Якщо обидва вузли NULL, то вони дзеркальні
    if (!p && !q) {
        return true;
    }

    // Якщо один з вузлів NULL, а інший - ні, то вони не дзеркальні
    if (!p || !q) {
        return false;
    }

    // Перевіряємо значення вузлів та рекурсивно викликаємо функцію для лівого та правого піддерев
    return (p->val == q->val) && isMirror(p->left, q->right) && isMirror(p->right, q->left);
}

bool isSymmetric(TreeNode* root) {
    // Перевірка, чи є дерево дзеркальним відносно свого центру
    return isMirror(root, root);
}

int main() {
    // Створення прикладів бінарних дерев
    TreeNode* example1 = new TreeNode(1);
    example1->left = new TreeNode(2);
    example1->right = new TreeNode(2);
    example1->left->left = new TreeNode(3);
    example1->left->right = new TreeNode(4);
    example1->right->left = new TreeNode(4);
    example1->right->right = new TreeNode(3);

    TreeNode* example2 = new TreeNode(1);
    example2->left = new TreeNode(2);
    example2->right = new TreeNode(2);
    example2->left->right = new TreeNode(3);
    example2->right->right = new TreeNode(3);

    TreeNode* example3 = new TreeNode(1);
    example3->left = new TreeNode(2);
    example3->right = new TreeNode(1);

    // Перевірка
    cout << "Example 1: " << (isSymmetric(example1) ? "true" : "false") << endl;
    cout << "Example 2: " << (isSymmetric(example2) ? "true" : "false") << endl;
    cout << "Example 3: " << (isSymmetric(example3) ? "true" : "false") << endl;

    return 0;
}
