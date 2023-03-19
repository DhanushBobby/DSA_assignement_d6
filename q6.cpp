#include <iostream>
#include <queue>
#include <map>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val): data(val), left(NULL), right(NULL) {}
};

void printTopView(Node* root) {
    if (!root) return;

    queue<pair<Node*, int>> q; // Node and its horizontal distance
    map<int, int> mp; // horizontal distance and its value

    q.push({root, 0});

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        Node* node = curr.first;
        int hd = curr.second;

        if (mp.find(hd) == mp.end()) {
            mp[hd] = node->data;
            cout << node->data << " ";
        }

        if (node->left) q.push({node->left, hd-1});
        if (node->right) q.push({node->right, hd+1});
    }
}

void printBottomView(Node* root) {
    if (!root) return;

    queue<pair<Node*, int>> q; // Node and its horizontal distance
    map<int, int> mp; // horizontal distance and its value

    q.push({root, 0});

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        Node* node = curr.first;
        int hd = curr.second;

        mp[hd] = node->data;

        if (node->left) q.push({node->left, hd-1});
        if (node->right) q.push({node->right, hd+1});
    }

    for (auto it = mp.begin(); it != mp.end(); it++) {
        cout << it->second << " ";
    }
}

int main() {
    // Create a binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(5);
    root->left->right->right->right = new Node(6);

    cout << "Top View: ";
    printTopView(root);

    cout << "\nBottom View: ";
    printBottomView(root);

    return 0;
}
