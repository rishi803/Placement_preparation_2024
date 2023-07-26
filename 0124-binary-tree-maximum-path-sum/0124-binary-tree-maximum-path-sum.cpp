
class Solution {
public:
    int ans=-1e4;
    
    int help(TreeNode* root){
        if(!root) return -1e4;
        
        int leftsum= help(root->left);
        int rightsum=help(root->right);
        
        ans=max({ans,leftsum,rightsum,root->val+leftsum,root->val+rightsum,root->val,root->val+leftsum+rightsum});
        // cout<<leftsum<<" "<<rightsum<<" "<<ans<<endl;
        return max({root->val+leftsum,root->val+rightsum,root->val});
    }
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        help(root);
        return ans;
    }
};