#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Traverse the left boundary, excluding leaf nodes
    void traversleft(Node* root, vector<int> &ans){
        if(root == NULL || (root->left == NULL && root->right == NULL)) return;
        ans.push_back(root->data);
        if(root->left) traversleft(root->left, ans);
        else traversleft(root->right, ans);
    }

    // Traverse all leaf nodes
    void traversleaf(Node* root, vector<int> &ans){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) ans.push_back(root->data);
        traversleaf(root->left, ans);
        traversleaf(root->right, ans);
    }

    // Traverse the right boundary, excluding leaf nodes, in reverse order
    void traversright(Node* root, vector<int> &ans){
        if(root == NULL || (root->left == NULL && root->right == NULL)) return;
        if(root->right) traversright(root->right, ans);
        else traversright(root->left, ans);
        ans.push_back(root->data); // Append after recursive calls for reverse order
    }

    vector<int> boundary(Node* root){
        vector<int> ans;
        if(root == NULL) return ans;
        
        // Root node
        ans.push_back(root->data);
        
        // Left boundary (excluding root and leaves)
        traversleft(root->left, ans);

        // All leaf nodes
        traversleaf(root->left, ans);
        traversleaf(root->right, ans);

        // Right boundary (excluding root and leaves, in reverse order)
        traversright(root->right, ans);

        return ans;
    }
};

// Helper function to test the boundary traversal
int main() {
    // Constructing a simple binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    // Create a solution object
    Solution sol;
    vector<int> result = sol.boundary(root);
    
    // Output the boundary traversal
    cout << "Boundary Traversal: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
