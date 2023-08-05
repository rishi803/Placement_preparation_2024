
class Solution {
public:
    
    bool help(TreeNode* root, long lrange, long rrange){
        
        if(!root) return true;
        
         return (root->val > lrange and root->val < rrange) and 
                help(root->left,lrange,root->val) and
                help(root->right,root->val,rrange);
      
        
    }
    
    bool isValidBST(TreeNode* root) {
        
        long lrange= -1e10;
        long rrange= 1e10;
        return help(root, lrange , rrange);
    }
};