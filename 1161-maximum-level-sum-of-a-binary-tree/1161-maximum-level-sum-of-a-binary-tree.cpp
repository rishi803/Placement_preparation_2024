
class Solution {
public:
    
    int maxLevelSum(TreeNode* root) {
        int level=1,mx=INT_MIN,ans=1;
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            int sz=q.size();
            int sum=0;
            while(sz--){
                auto f=q.front();
                q.pop();
                sum+=f->val;
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
            }
            if(mx<sum){
               ans=level;
                mx=sum;
            }
            level++;
        }
        return ans;
    }
};