
class Solution {
public:
    
    int ans=0;
     void help(TreeNode* root,int &k){
        if(!root) return;
        help(root->left,k);
        k--;
        if(k==0) {
            ans=root->val;
            return;
        }
        help(root->right,k);
        
    }
    
    int kthSmallest(TreeNode* root, int k) {
        
         help(root,k);
        return ans;
    }
};