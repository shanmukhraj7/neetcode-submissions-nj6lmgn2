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
    int diameterOfBinaryTree(TreeNode* root) {
        int maxv = 0;
        function<int(TreeNode*)> solve = [&] (TreeNode* node) -> int {
            if(!node) return 0;
            int left = solve(node->left);
            int right = solve(node->right);
            maxv = max(maxv, 1 + left + right);
            return 1 + max(left, right);
        };
        int val = solve(root);
        return maxv - 1;
    }
};
