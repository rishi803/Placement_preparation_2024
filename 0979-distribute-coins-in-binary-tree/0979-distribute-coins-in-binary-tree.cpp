
class Solution {
public:
    
    int cnt= 0;
    int help(TreeNode* root){
        if(!root) return 0;
        
        int left= help(root->left);
        int right=help(root->right);
        
        cnt+= abs(left) + abs(right);
        
        return root->val + (left + right) - 1;
    }
    
    int distributeCoins(TreeNode* root) {
        
         help(root);
        return cnt;
    }
};