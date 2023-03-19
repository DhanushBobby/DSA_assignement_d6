#include <iostream>
#include <queue>
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

void leftView(Node* root) {
   if (root == NULL) return;

   queue<Node *> q;
   q.push(root);

   while (!q.empty()) {
      int count = q.size();

      for (int i = 0; i < count; i++) {
         Node *node = q.front();
         q.pop();

         if (i == 0)
            cout << node->data << " ";

         if (node->left != NULL)
            q.push(node->left);

         if (node->right != NULL)
            q.push(node->right);
      }
   }
}

void rightView(Node* root) {
   if (root == NULL) return;

   queue<Node *> q;
   q.push(root);

   while (!q.empty()) {
      int count = q.size();

      for (int i = 0; i < count; i++) {
         Node *node = q.front();
         q.pop();

         if (i == count - 1)
            cout << node->data << " ";

         if (node->left != NULL)
            q.push(node->left);

         if (node->right != NULL)
            q.push(node->right);
      }
   }
}

int main() {
   Node *root = newNode(1);
   root->left = newNode(2);
   root->right = newNode(3);
   root->left->left = newNode(4);
   root->left->right = newNode(5);

   cout << "Left View of binary tree is \n";
   leftView(root);

   cout << "\nRight View of binary tree is \n";
   rightView(root);

   return 0;
}