#include <bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    public:
        TreeNode* invertTree(TreeNode* root) {
            if(root == nullptr) return nullptr;
            TreeNode* left = invertTree(root->left);
            TreeNode* right = invertTree(root->right);
    
            root->left = right;
            root->right = left;
            
            return root;
        }
};

void printTree(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        cout << node->val << " ";
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    cout << endl;
}

int main() {
    Solution s;
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    cout << "Original Tree: ";
    printTree(root);
    
    TreeNode* result = s.invertTree(root);

    cout << "Inverted Tree: ";
    printTree(result);
    
    return 0;
}
