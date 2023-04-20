
class Solution {
public:
    int maxheight(TreeNode* root){
        if(!root) return 0;
        
        return 1+max(maxheight(root->left),maxheight(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        if(!root) return 0;
        
        int op1=maxheight(root->left)+maxheight(root->right);
        int op2=diameterOfBinaryTree(root->left);
        int op3=diameterOfBinaryTree(root->right);
        
        return max({op1,op2,op3});
    }
};