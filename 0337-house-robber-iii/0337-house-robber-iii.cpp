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
    
    pair<int,int> help(TreeNode* root){
        
        if(!root) return {0,0};                        // pair(include,exclude)
        pair<int,int>leftans=help(root->left);
        pair<int,int>rightans=help(root->right);
        
        int include_root=root->val+leftans.second+rightans.second;
        int exclude_root=max(leftans.first,leftans.second)+max(rightans.first,rightans.second);
        
        return {include_root,exclude_root};
    }
    
    int rob(TreeNode* root) {
        pair<int,int>ans=help(root);
        return max(ans.first,ans.second);
    }
};