
class Solution {
public:
    
    int ans= 0;
    
    int help(TreeNode* root){
        if(!root) return 0;
        
//         root->val+= help(root->left);
//         root->val+=help(root->right);
        
//         int remain= root->val - 1;
        
//         ans+= abs(remain);
        
//         return remain;
        
        int left= help(root->left);
        int right= help(root->right);
        
        ans+= abs(left) + abs(right);
        
        return root->val + left + right - 1;
        
    }
    
    int distributeCoins(TreeNode* root) {
        
         help(root);
        return ans;
    }
};