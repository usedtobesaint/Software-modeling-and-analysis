#include <iostream>

using namespace std;

// Визначення структури вузла бінарного дерева
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {
    // Якщо обидва вузли NULL, то вони однакові
    if (!p && !q) {
        return true;
    }

    // Якщо один з вузлів NULL, а інший - ні, то вони неоднакові
    if (!p || !q) {
        return false;
    }

    // Перевіряємо значення вузлів та рекурсивно викликаємо функцію для лівого і правого піддерев
    return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main() {
    // Створення прикладів бінарних дерев
    TreeNode* p1 = new TreeNode(1);
    p1->left = new TreeNode(2);
    p1->right = new TreeNode(3);

    TreeNode* q1 = new TreeNode(1);
    q1->left = new TreeNode(2);
    q1->right = new TreeNode(3);

    TreeNode* p2 = new TreeNode(1);
    p2->left = new TreeNode(2);

    TreeNode* q2 = new TreeNode(1);
    q2->right = new TreeNode(2);

    TreeNode* p3 = new TreeNode(1);
    p3->left = new TreeNode(2);
    p3->right = new TreeNode(1);

    TreeNode* q3 = new TreeNode(1);
    q3->left = new TreeNode(1);
    q3->right = new TreeNode(2);

    // Перевірка
    cout << "Example 1: " << (isSameTree(p1, q1) ? "true" : "false") << endl;
    cout << "Example 2: " << (isSameTree(p2, q2) ? "true" : "false") << endl;
    cout << "Example 3: " << (isSameTree(p3, q3) ? "true" : "false") << endl;

    return 0;
}
