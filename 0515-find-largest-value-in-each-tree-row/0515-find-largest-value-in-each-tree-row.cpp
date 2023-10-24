
class Solution {
public:
    
     vector<int>ans;
    
    void help(TreeNode* root, int level){
        if(!root) return;
        
      
    // If the vector size is not enough, resize it
    if (ans.size() <= level) {
        ans.push_back(INT_MIN);
    }

    // Update the maximum value for the current level
    ans[level] = max(ans[level], root->val);

    // Recursively process the left and right subtrees
     help(root->left, level + 1);
     help(root->right, level + 1);
    }
    
    vector<int> largestValues(TreeNode* root) {
        
        if(!root) return {};
        help(root,0);
        return ans;
       
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