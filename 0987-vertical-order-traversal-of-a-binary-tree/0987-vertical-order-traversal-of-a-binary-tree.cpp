/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        if (root == nullptr)
            return {};

        // Column -> Row -> Sorted Node Values
        map<int, map<int, multiset<int>>> nodes;
        // BFS: {Node, {Column, Row}}
        queue<pair<TreeNode*, pair<int, int>>> todo;
        todo.push({root, {0, 0}});
        // BFS Traversal
        while (!todo.empty()) {
            auto p = todo.front();
            todo.pop();

            TreeNode* node = p.first;
            int x = p.second.first;
            int y = p.second.second;
            // Store node value
            nodes[x][y].insert(node->val);
            // Left child
            if (node->left)
                todo.push({node->left, {x - 1, y + 1}});
            // Right child
            if (node->right)
                todo.push({node->right, {x + 1, y + 1}});
        }

        // final answer
        vector<vector<int>> ans;
        for (auto p : nodes) {
            vector<int> col;
            for (auto q : p.second)
                col.insert(col.end(), q.second.begin(), q.second.end());

            ans.push_back(col);
        }
        return ans;
    }
};