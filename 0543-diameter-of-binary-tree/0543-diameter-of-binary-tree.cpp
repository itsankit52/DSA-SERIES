/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root) {
        if (root == nullptr)
            return 0;

        return 1 + max(height(root->left), height(root->right));
    }

    void solve(TreeNode* root, int &maximum) {
        if (root == nullptr)
            return;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int diameter = leftHeight + rightHeight;
        maximum = max(maximum, diameter);
        solve(root->left, maximum);
        solve(root->right, maximum);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maximum = 0;
        solve(root, maximum);
        return maximum;
    }
};