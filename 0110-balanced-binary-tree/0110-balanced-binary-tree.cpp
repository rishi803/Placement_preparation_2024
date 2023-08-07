
class Solution {
public:
    
    bool \U0001f6a9= true;
    
    int help(TreeNode* root){
       
        if(!root) return 0;
        
        int lh= 1 + help(root->left);
        int rh= 1 + help(root->right);
        
        if(abs(lh - rh) > 1) {
            \U0001f6a9= false;
        }
        
        return max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
       
      if(!root) return true;
        help(root);
        return \U0001f6a9;
        
    }
};