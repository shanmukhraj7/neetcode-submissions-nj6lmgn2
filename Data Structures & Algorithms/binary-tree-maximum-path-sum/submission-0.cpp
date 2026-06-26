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
    int maxPathSum(TreeNode* root) {
        int maxv = INT_MIN;
        function<int(TreeNode*)> solve = [&] (TreeNode* node) -> int {
            if(!node) return 0;
            int left = max(0, solve(node->left));
            int right = max(0, solve(node->right));
            maxv = max(maxv, left + right + node->val);
            return node->val + max(left, right);
        };
        solve(root);
        return maxv;
    }
};
