
class Solution {
public:
    
    int ans= 0;
    
    pair<int,int> help(TreeNode* root){
        if(!root) return {0,0};
        
        // if(!root->left and !root->right) return {root->val, 1};
        
        pair<int,int>left= help(root->left);
        pair<int,int>right= help(root->right);
        
        int totalsum= root->val + left.first + right.first;
        int totalnodes= 1 + left.second + right.second;
        
        // cout<<totalsum<<" "<<totalnodes<<endl;
        
        if((totalsum/totalnodes) == root->val) ans++;
        
        return {totalsum, totalnodes};
    }
    
    int averageOfSubtree(TreeNode* root) {
        help(root);
        return ans;
    }
};