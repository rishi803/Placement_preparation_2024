
class Solution {
public:
    
    TreeNode* help(TreeNode* root, TreeNode* p, TreeNode* q){
        
        if(!root) return nullptr;
        
        if(root->val == p->val or root->val == q->val) return root;
         
               TreeNode* left=  help(root->left, p, q);
               TreeNode* right= help(root->right, p, q);
        
        if(left and right) return root;
        if(left and !right) return left;
       else return right;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
          return help(root,p,q);
    }
};