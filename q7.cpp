#include <iostream>
#include <algorithm>
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

int height(Node* root) {
   if (root == NULL) return 0;

   return 1 + max(height(root->left), height(root->right));
}

int size(Node* root) {
   if (root == NULL) return 0;

   return 1 + size(root->left) + size(root->right);
}

int diameter(Node* root) {
   if (root == NULL) return 0;

   int lheight = height(root->left);
   int rheight = height(root->right);

   int ldiameter = diameter(root->left);
   int rdiameter = diameter(root->right);

   return max(lheight + rheight + 1, max(ldiameter, rdiameter));
}

int main() {
   Node *root = newNode(1);
   root->left = newNode(2);
   root->right = newNode(3);
   root->left->left = newNode(4);
   root->left->right = newNode(5);

   cout << "Height of binary tree is " << height(root) << endl;
   cout << "Size of binary tree is " << size(root) << endl;
   cout << "Diameter of binary tree is " << diameter(root) << endl;

   return 0;
}