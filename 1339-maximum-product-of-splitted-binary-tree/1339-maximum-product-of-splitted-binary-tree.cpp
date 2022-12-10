
class Solution {
public:
    long total=0,ans=0,every_sub_tree_sum;
    int maxProduct(TreeNode* root) {
        total=total_sum_remain_tree(root);
        total_sum_remain_tree(root);
        return ans% (int)(1e9+7);
    }
    
    int total_sum_remain_tree(TreeNode* root){
        if(!root) return 0;
        every_sub_tree_sum=root->val+total_sum_remain_tree(root->left)+total_sum_remain_tree(root->right);
         ans=max(ans,every_sub_tree_sum*(total-every_sub_tree_sum));
        return every_sub_tree_sum;
    }
  
};