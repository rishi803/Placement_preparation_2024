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
    
    unordered_map<TreeNode*,vector<int>>dp;       //WHY INT DP OR 2D VECTOR DP NOT WORKING  (failing on [79,99,77,null,null,null,69,null,60,53,null,73,11,null,null,null,62,27,62,null,null,98,50,null,null,90,48,82,null,null,null,55,64,null,null,73,56,6,47,null,93,null,null,75,44,30,82,null,null,null,null,null,null,57,36,89,42,null,null,76,10,null,null,null,null,null,32,4,18,null,null,1,7,null,null,42,64,null,null,39,76,null,null,6,null,66,8,96,91,38,38,null,null,null,null,74,42,null,null,null,10,40,5,null,null,null,null,28,8,24,47,null,null,null,17,36,50,19,63,33,89,null,null,null,null,null,null,null,null,94,72,null,null,79,25,null,null,51,null,70,84,43,null,64,35,null,null,null,null,40,78,null,null,35,42,98,96,null,null,82,26,null,null,null,null,48,91,null,null,35,93,86,42,null,null,null,null,0,61,null,null,67,null,53,48,null,null,82,30,null,97,null,null,null,1,null,null])
    
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
        // memset(dp,-1,sizeof(dp));
        return help(root,1);
      
    }
};