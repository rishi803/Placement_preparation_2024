
class Solution {
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        Stack<TreeNode>st1=new Stack();
        Stack<TreeNode>st2=new Stack();
        
         st1.push(root1);
         st2.push(root2);
        
        while(st1.size()>0 && st2.size()>0){
           if(dfs(st1)!=dfs(st2)) return false;
        }
        return st1.size()==st2.size();
          
    }
    
    public int dfs(Stack<TreeNode>st){
        while(true){
            TreeNode node=st.pop();
            if(node.right!=null) st.push(node.right);
            if(node.left!=null) st.push(node.left);
            if(node.left==null && node.right==null) return node.val;
        }
    }
}