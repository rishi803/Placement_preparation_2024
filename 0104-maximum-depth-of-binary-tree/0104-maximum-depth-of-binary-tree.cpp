
class Solution {
public:
    
    int help(TreeNode* root){
        
        if(!root) return 0;
        
           int l=  help(root->left);
        
          int r=   help(root->right);
        
        return 1+ max(l,r);
        
        
        
    }
    
    int maxDepth(TreeNode* root) {
              return help(root);
    }
};