long res = 0, total = 0, sub;
int maxProduct(TreeNode* root) {
total = s(root), s(root);
return res % (int)(1e9 + 7);
}
​
int s(TreeNode* root) {
if (!root) return 0;
sub = root->val + s(root->left) + s(root->right);
res = max(res, sub * (total - sub));
return sub;
}
/////////////////java////////////////
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
//////////////////python/////////////////////////
class Solution:
def maxProduct(self, root: Optional[TreeNode]) -> int:
def dfs(root):
if root == None: return 0
currSum = dfs(root.left) + dfs(root.right) + root.val
self.ans = max(self.ans, currSum * (self.totalSum - currSum))
return currSum
​
self.ans, self.totalSum = 0, 0
self.totalSum = dfs(root)  # Firstly, get total sum of all nodes in the Binary Tree
dfs(root)  # Then dfs in post order to calculate sum of each subtree and its complement
return self.ans % (10 ** 9 + 7)