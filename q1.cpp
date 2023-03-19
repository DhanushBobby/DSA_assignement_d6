#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

void inorder(Node* node) {
    if (node == NULL)
        return;

    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

void preorder(Node* node) {
    if (node == NULL)
        return;

    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

void postorder(Node* node) {
    if (node == NULL)
        return;

    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}

int main() {
   Node *root = newNode(1);
   root->left = newNode(2);
   root->right = newNode(3);
   root->left->left = newNode(4);
   root->left->right = newNode(5);

   cout << "\nInorder traversal of binary tree is \n";
   inorder(root);

   cout << "\nPreorder traversal of binary tree is \n";
   preorder(root);

   cout << "\nPostorder traversal of binary tree is \n";
   postorder(root);

   return 0;
}