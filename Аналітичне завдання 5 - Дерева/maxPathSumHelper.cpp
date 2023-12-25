#include <iostream>
#include <algorithm>

using namespace std;

// Визначення структури вузла бінарного дерева
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Допоміжна функція для обчислення максимальної суми шляху для кожного вузла
int maxPathSumHelper(TreeNode* root, int& result) {
    if (!root) {
        return 0;
    }

    // Рекурсивно обчислити суму шляху для лівого та правого піддерев
    int leftSum = max(0, maxPathSumHelper(root->left, result));
    int rightSum = max(0, maxPathSumHelper(root->right, result));

    // Обчислити максимальну суму шляху, яка проходить через поточний вузол
    int currentSum = root->val + leftSum + rightSum;

    // Оновити глобальний результат, якщо поточна сума більша
    result = max(result, currentSum);

    // Повернути максимальну суму шляху, що проходить вгору через вузол
    return root->val + max(leftSum, rightSum);
}

// Основна функція для обчислення максимальної суми шляху в бінарному дереві
int maxPathSum(TreeNode* root) {
    int result = INT_MIN;
    maxPathSumHelper(root, result);
    return result;
}

int main() {
    // Приклад 1
    TreeNode* example1 = new TreeNode(1);
    example1->left = new TreeNode(2);
    example1->right = new TreeNode(3);

    cout << "Example 1: " << maxPathSum(example1) << endl;

    // Приклад 2
    TreeNode* example2 = new TreeNode(-10);
    example2->left = new TreeNode(9);
    example2->right = new TreeNode(20);
    example2->right->left = new TreeNode(15);
    example2->right->right = new TreeNode(7);

    cout << "Example 2: " << maxPathSum(example2) << endl;

    return 0;
}
