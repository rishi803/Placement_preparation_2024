
class Solution {
public:
    bool flag=true;
    int help(TreeNode* root){
        if(!root) return 0;
        int lefth=1+help(root->left);
        int righth=1+help(root->right);
        // cout<<lefth<<" "<<righth<<endl;
        if (abs(lefth-righth)>1) {
            flag=false;
            return 1e5;
        }
        else return max(lefth,righth);
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
          help(root);
        return flag;
    }
};