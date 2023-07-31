
class Solution {
public:
    
    pair<int,int> help(TreeNode* root){
        if(!root) return {0,0};
        
        pair<int,int> left=  help(root->left);
        pair<int,int> right= help(root->right);
        
        return {1+ max(left.first,right.first),max(left.first+right.first,max(left.second,right.second))} ;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        pair<int,int>ans= help(root);
        return ans.second;
    }
};