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
    int goodNodes(TreeNode* root) {
        int count = 0, maxv = root->val;
        function<void(TreeNode*, int maxv)> solve = [&] (TreeNode* node, int maxv) {
            if(!node) return;
            if(node->val >= maxv){
                maxv = node->val;
                count++;
            }
            solve(node->left, maxv);
            solve(node->right, maxv);
        };
        solve(root, root->val);
        return count;
    }
};
