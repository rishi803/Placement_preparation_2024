
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        
        queue<TreeNode*>q;
        q.push(root);
        
        bool flag=true;
      
        
        while(!q.empty()){
            
            auto f=q.front();
            q.pop();
            
            if(!f->left) flag=false; 
            
            if(flag==false and f->right or flag==false and f->left) return false;
            if(f->left) q.push(f->left);
            
            if(f->right) q.push(f->right);
            
            if(!f->right) flag=false;
         
        }
    
        return true;
    }
};