
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        
        if(!root) return {};
        vector<int>ans;
        queue<TreeNode*>q;
        q.push(root);
   
        while(!q.empty()){
            int sz= q.size();
            int mx= INT_MIN;
            
            while(sz--){
                auto f= q.front();
                q.pop();
                
                if(f->left){
                    q.push(f->left);
                }
                
                if(f->right){
                    q.push(f->right);
                }
                
                mx= max(mx,f->val);
            }
            
            ans.push_back(mx);
        }
        
        return ans;
    }
};