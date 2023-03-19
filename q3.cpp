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

void levelOrderLineByLine(Node* root) {
   if (root == NULL) return;

   queue<Node *> q;
   q.push(root);

   while (!q.empty()) {
      int count = q.size();

      while (count--) {
         Node *node = q.front();
         cout << node->data << " ";
         q.pop();

         if (node->left != NULL)
            q.push(node->left);

         if (node->right != NULL)
            q.push(node->right);
      }
      cout << endl;
   }
}

int main() {
   Node *root = newNode(1);
   root->left = newNode(2);
   root->right = newNode(3);
   root->left->left = newNode(4);
   root->left->right = newNode(5);

   cout << "Level Order traversal of binary tree line by line is \n";
   levelOrderLineByLine(root);

   return 0;
}