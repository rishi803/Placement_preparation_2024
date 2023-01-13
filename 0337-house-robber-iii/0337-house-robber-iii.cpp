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

// TEST CASE: [2,1,3,null,4],       [4,1,null,2,null,]
class Solution {
public:
    
//     pair<int,int> help(TreeNode* root){
        
//         if(!root) return {0,0};                        // pair(include,exclude)
//         pair<int,int>leftans=help(root->left);
//         pair<int,int>rightans=help(root->right);
        
//         int include_root=root->val+leftans.second+rightans.second;
//         int exclude_root=max(leftans.first,leftans.second)+max(rightans.first,rightans.second);
        
//         return {include_root,exclude_root};
//     }
    
//     int rob(TreeNode* root) {
//         pair<int,int>ans=help(root);
//         return max(ans.first,ans.second);
//     }
    
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