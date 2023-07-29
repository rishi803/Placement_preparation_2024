
class Solution {
public:
    bool help(TreeNode* root,TreeNode* sub){
        if(!root and !sub) return true;
        if(!root or !sub) return false;
        if (root->val != sub->val) return false;
    
            return help(root->left,sub->left) and help(root->right,sub->right);
        
        
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
      
          if(!s) return false;
          if (help(s,t)) return true;
        
        return isSubtree(s->left,t) || isSubtree(s->right,t);
    
        
    }
};