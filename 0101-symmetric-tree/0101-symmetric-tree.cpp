
class Solution {
public:
    
    bool help(TreeNode* l, TreeNode* r){
        if(!l and !r) return true;
        if(l and !r or !l and r) return false;
        if(l->val!=r->val) return false;
        
        return help(l->left,r->right) and help(l->right,r->left);
    }
    bool isSymmetric(TreeNode* root) {
        
        return help(root->left,root->right);
    }
};