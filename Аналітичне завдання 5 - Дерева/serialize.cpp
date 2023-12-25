#include <iostream>
#include <sstream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// Визначення структури вузла бінарного дерева
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Функція для серіалізації бінарного дерева в рядок
string serialize(TreeNode* root) {
    if (!root) {
        return "[]";
    }

    // Використання обхіду у ширину (BFS) для серіалізації
    string result = "[";
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        if (current) {
            result += to_string(current->val) + ",";
            q.push(current->left);
            q.push(current->right);
        }
        else {
            result += "null,";
        }
    }

    // Видалення зайвої коми та закриваючої дужки
    result.pop_back();
    result += "]";
    return result;
}

// Функція для десеріалізації рядка у бінарне дерево
TreeNode* deserialize(string data) {
    if (data == "[]") {
        return nullptr;
    }

    // Розділення рядка за комами
    stringstream ss(data.substr(1, data.size() - 2));
    string token;
    vector<TreeNode*> nodes;

    while (getline(ss, token, ',')) {
        if (token == "null") {
            nodes.push_back(nullptr);
        }
        else {
            nodes.push_back(new TreeNode(stoi(token)));
        }
    }

    // Використання обхіду у ширину (BFS) для десеріалізації
    TreeNode* root = nodes[0];
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();

        if (i < nodes.size() && nodes[i]) {
            current->left = nodes[i];
            q.push(nodes[i]);
        }
        i++;

        if (i < nodes.size() && nodes[i]) {
            current->right = nodes[i];
            q.push(nodes[i]);
        }
        i++;
    }

    return root;
}

int main() {
    // Приклад 1: Серіалізація та десеріалізація бінарного дерева
    TreeNode* example1 = new TreeNode(1);
    example1->left = new TreeNode(2);
    example1->right = new TreeNode(3);
    example1->right->left = new TreeNode(4);
    example1->right->right = new TreeNode(5);

    string serialized = serialize(example1);
    cout << "Serialized: " << serialized << endl;

    TreeNode* deserialized = deserialize(serialized);
    string reserialized = serialize(deserialized);
    cout << "Reserialized: " << reserialized << endl;

    // Приклад 2: Серіалізація та десеріалізація пустого бінарного дерева
    TreeNode* example2 = nullptr;

    string serializedEmpty = serialize(example2);
    cout << "Serialized Empty: " << serializedEmpty << endl;

    TreeNode* deserializedEmpty = deserialize(serializedEmpty);
    string reserializedEmpty = serialize(deserializedEmpty);
    cout << "Reserialized Empty: " << reserializedEmpty << endl;

    return 0;
}
