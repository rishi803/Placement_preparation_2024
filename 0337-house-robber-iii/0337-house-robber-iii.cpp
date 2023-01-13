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
    
    unordered_map<TreeNode*,vector<int>>dp;      
    
    int help(TreeNode* root,bool canrob){
        if(!root) return 0;
        if(dp.count(root) && dp[root][canrob] != -1) return dp[root][canrob];
        dp[root] = {-1,-1};
        int takeroot=0;
            if(canrob)
            takeroot=root -> val + help(root -> left, false) + help(root -> right, false);
        
        int notroot= 0;
          notroot=help(root->left,true)+help(root->right,true);
        
        return dp[root][canrob]=max(takeroot,notroot);
    }
    int rob(TreeNode* root) {
        return help(root,1);
      
    }
};