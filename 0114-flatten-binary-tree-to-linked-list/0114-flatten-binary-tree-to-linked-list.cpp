
class Solution {
public:
    
    TreeNode* prev=nullptr;
        
    void flatten(TreeNode* root) {
        if(!root) return ;
        
        flatten(root->right);
        flatten(root->left);
        root->right= prev;
         prev = root;
        root->left=nullptr;
       
    }
};