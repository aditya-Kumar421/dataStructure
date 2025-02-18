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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) return 0;
        
        int sum = 0;
        
        // Check if left child exists and is a leaf
        if (root->left && root->left->left == nullptr && root->left->right == nullptr) {
            sum += root->left->val;
        }
        
        // Recursively find sum in left and right subtrees
        sum += sumOfLeftLeaves(root->left);
        sum += sumOfLeftLeaves(root->right);
        
        return sum;
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution s;
    cout << "Sum of left leaves: " << s.sumOfLeftLeaves(root) << endl;

    return 0;
}
