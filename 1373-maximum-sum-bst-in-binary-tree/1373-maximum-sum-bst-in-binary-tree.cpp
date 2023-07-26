
class Solution {
    
    struct rishi{
        public:
        bool isbst;
        int mn,mx,sum;
    };
    
    rishi helper(TreeNode* root,int &ans){
        if(!root) return {true,INT_MAX,INT_MIN,0};
        
        rishi left= helper(root->left,ans);
        rishi right= helper(root->right,ans);
        
        if(left.isbst and right.isbst and root->val>left.mx and root->val<right.mn){
            int sum=left.sum+right.sum+root->val;
            ans=max(ans,sum);
            
            return {true,min(left.mn,root->val),max(right.mx,root->val),sum};
        }
        else{
            return {false,0,0,0};
        }
    }
    
public:
    int maxSumBST(TreeNode* root) {
        int ans=0;
        if(!root) return 0;
        helper(root,ans);
        return ans;
    }
};