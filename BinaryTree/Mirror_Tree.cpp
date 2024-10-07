#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        if(node == NULL) return;
        
        // Recursively mirror left and right subtrees
        mirror(node->left);
        mirror(node->right);
        
        // Swap left and right children
        Node* temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
};

// Helper function to print the tree in inorder traversal
void inorder(Node* node) {
    if (node == NULL) return;
    
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

int main() {
    // Construct a binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    
    // Print inorder traversal before mirroring
    cout << "Inorder traversal before mirroring: ";
    inorder(root);
    cout << endl;
    
    // Create a solution object and mirror the tree
    Solution sol;
    sol.mirror(root);
    
    // Print inorder traversal after mirroring
    cout << "Inorder traversal after mirroring: ";
    inorder(root);
    cout << endl;

    return 0;
}
