
class Solution {
public:
    bool flag=true;
    int help(TreeNode* root){
        if(!root) return 0;
        int lefth=1+help(root->left);
        int righth=1+help(root->right);
        // cout<<lefth<<" "<<righth<<endl;
        if (abs(lefth-righth)>1) {               // we have got the unbalanced height
            flag=false;
            return 1e5;                        
        }
        else return max(lefth,righth);      // send max height from left sub and right sub
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
          help(root);
        return flag;
    }
};