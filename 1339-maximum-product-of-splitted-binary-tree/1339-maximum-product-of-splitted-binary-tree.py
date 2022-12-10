
class Solution:
    def maxProduct(self, root: Optional[TreeNode]) -> int:
        def dfs(root):
            if root==None:
                return 0
            currSum=root.val+dfs(root.left)+dfs(root.right)
            self.ans=max(self.ans,currSum*(self.total-currSum))
            return currSum
        
        self.ans=self.total=0
        self.total=dfs(root)
        dfs(root)
        return self.ans %(10**9+7)