
class Solution {
public:
    int ans=-1e4;
    
    int help(TreeNode* root){
        if(!root) return 0;
        
        int leftsum= help(root->left);
        int rightsum=help(root->right);
        
       ans=max({
           ans,
           root->val,
           // leftsum, 
           // rightsum,
           root->val+leftsum,
           root->val+rightsum,
           root->val+leftsum+rightsum
       });
        
        return max({
            root->val,
            root->val+leftsum,
            root->val+rightsum
        });
    }
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        help(root);
        return ans;
    }
};