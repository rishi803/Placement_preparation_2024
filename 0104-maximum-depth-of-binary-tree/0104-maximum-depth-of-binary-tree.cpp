
class Solution {
public:
    int help(TreeNode* root){
        if(!root) return 0;
        // if(!root->left and !root->right) return 1;
        int l=1+help(root->left);
        int r=1+help(root->right);
        return max(l,r);
    }
    int maxDepth(TreeNode* root) {
        int ans=help(root);
        return ans;
    }
};