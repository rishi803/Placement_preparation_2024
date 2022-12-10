
class Solution {
    long ans=0,total=0,sum;
    
    public int maxProduct(TreeNode root) {
        total=rec(root);
        rec(root);
        return (int)(ans%(int)(1e9+7));
    }
    
    public long rec(TreeNode root){
        if(root==null) return 0;
        sum=root.val+rec(root.left)+rec(root.right);
        ans=Math.max(ans,sum*(total-sum));
        return  sum;
    }
}