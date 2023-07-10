
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int>ans;
       
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
      
        while(!q.empty()){
              int flag=0;
            int sz=q.size();
            while(sz--){
                auto node=q.front();
                q.pop();
                
                if(flag==0) ans.push_back(node->val),flag=1;
                
                if(node->right) q.push(node->right);
                if(node->left) q.push(node->left);
                
                
            }
            level++;
        }
        
        return ans;
    }
};