
class Solution {
public:
       unordered_map<TreeNode*,vector<int>>dp;   
    
    int help(TreeNode* root,bool flag){
        
        if(!root) return 0;
        if(dp.count(root) && dp[root][flag] != -1) return dp[root][flag];
        dp[root] = {-1,-1};
        
        int canrob=INT_MIN,notrob=INT_MIN;
        
        if(flag) {
             canrob=root->val+help(root->left,false)+help(root->right,false);
              notrob=help(root->left,true)+help(root->right,true);
        }
        
        else{
            notrob=help(root->left,true)+help(root->right,true);
        }
        
        return dp[root][flag]=max(canrob,notrob);
    }
    
    int rob(TreeNode* root) {
        
        return help(root,true);
    }
};