
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int>ans;
       
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto node=q.front();
                q.pop();
                
                if(ans.size()==level) ans.push_back(node->val);
                
                if(node->right) q.push(node->right);
                if(node->left) q.push(node->left);
                
                
            }
            level++;
        }
        
        return ans;
    }
};