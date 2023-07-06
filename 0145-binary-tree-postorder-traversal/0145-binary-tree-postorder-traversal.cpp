
class Solution {
public:
    
    vector<int>ans;
    
    void help(TreeNode* root){
           if(!root) return ;
               
        ans.push_back(root->val);;
        help(root->right);
 
        help(root->left);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        help(root);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};