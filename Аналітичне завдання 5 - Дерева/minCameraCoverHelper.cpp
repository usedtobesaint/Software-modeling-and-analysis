#include <iostream>
#include <climits>

using namespace std;

// Визначення структури вузла бінарного дерева
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Допоміжна функція для рекурсивного обходу дерева
int minCameraCoverHelper(TreeNode* root, int& cameras) {
    if (!root) {
        return 2; // Вузол не існує, вважаємо, що він покритий.
    }

    int left = minCameraCoverHelper(root->left, cameras);
    int right = minCameraCoverHelper(root->right, cameras);

    // Вузол покритий камерою
    if (left == 0 || right == 0) {
        cameras++;
        return 1; // Камера розміщена на поточному вузлі
    }

    // Вузол не покритий камерою, але його дочірні елементи покриті
    if (left == 1 || right == 1) {
        return 2; // Позначаємо вузол як покритий без розміщення камери
    }

    // Вузол і його дочірні елементи покриті
    return 0;
}

// Основна функція для знаходження мінімальної кількості камер
int minCameraCover(TreeNode* root) {
    int cameras = 0;
    if (minCameraCoverHelper(root, cameras) == 0) {
        // Корінь не покритий камерою, розміщуємо камеру на корені
        cameras++;
    }
    return cameras;
}

int main() {
    // Приклад 1
    TreeNode* example1 = new TreeNode(0);
    example1->left = new TreeNode(0);
    example1->right = new TreeNode(0);

    cout << "Example 1: " << minCameraCover(example1) << endl;

    // Приклад 2
    TreeNode* example2 = new TreeNode(0);
    example2->left = new TreeNode(0);
    example2->right = new TreeNode(0);
    example2->left->right = new TreeNode(0);

    cout << "Example 2: " << minCameraCover(example2) << endl;

    return 0;
}
