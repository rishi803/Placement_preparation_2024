
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
            
            return {
                    sum,
                    max(root->val,max(left.mx,right.mx)),     // jo sbase bdi value h subtree me
                    min(root->val,min(right.mn,left.mn)),     // jo sabse choti value h subtree me
                    true        // han bhai bst to hoga hi phir agr is loop me hai
                    };
        }
        else return {
            0,         // kuch nhi mila \U0001f62b
            123,       // kuch bhi likho ab yaha iska koi contribution nhi ab
            98,        // no use iska bhi kunki ab kabhi upar bst milega hi nhi
            false      // bst nhi hai phir aur kya \U0001f972
            };
        
    }
    
public:
    int maxSumBST(TreeNode* root) {
        help(root);
        return ans;
    }
};