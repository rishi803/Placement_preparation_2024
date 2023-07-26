
class Solution {
public:
    int ans=-1e4;
    
    int help(TreeNode* root){
        
        if(!root) return -1e4;
        
        int leftsum= help(root->left);
        int rightsum=help(root->right);
        
       ans=max({
           ans,                // update answer
           root->val,          // this root can be max
           leftsum,            // max answer lies in right
           rightsum,           // max answer lies in left 
           root->val+leftsum,  // max answer can be (root+left)
           root->val+rightsum, // max answer can be (root+right)
           root->val+leftsum+rightsum // max answer can be (root+left+right);
       });
        // cout<<leftsum<<" "<<rightsum<<" "<<root->val<<endl;
        return max({
            root->val,         
            // leftsum,          // [1,-2,-3,1,3,-2,null,-1] failing 
            // rightsum,         // [1,-2,-3,1,3,-2,null,-1] failing
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