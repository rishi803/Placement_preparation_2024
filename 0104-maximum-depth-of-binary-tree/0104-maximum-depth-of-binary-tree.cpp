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
    int help(TreeNode* root){
        if(!root) return 0;
        // if(!root->left and !root->right) return 1;
        return 1+max(help(root->left),help(root->right));
    }
    int maxDepth(TreeNode* root) {
        int ans=help(root);
        return ans;
    }
};