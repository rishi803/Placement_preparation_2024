
class Solution {
    
    int ans=0;
    
    struct rishi{
        public:
          int sum,mx,mn;
          bool isbst;
    };
    
    rishi help(TreeNode* root){
        if(!root) return {0,INT_MIN,INT_MAX,true};
        
        rishi left=     help(root->left);
        rishi right=    help(root->right);
        
        if(root->val > left.mx and root->val < right.mn and left.isbst and right.isbst){
            
            int sum= root->val + left.sum + right.sum;
            ans=max(ans,sum);
            
            return {sum,max(root->val,max(left.mx,right.mx)),min(root->val,min(right.mn,left.mn)),true};
        }
        else return {0,INT_MAX,INT_MIN,false};
        
    }
    
public:
    int maxSumBST(TreeNode* root) {
        help(root);
        return ans;
    }
};