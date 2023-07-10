
class Solution {
public:
    
     vector<int>ans;
    
    void dfs(TreeNode* root,int level){
        if(!root) return;
        
        if(ans.size()==level) ans.push_back(root->val);
        dfs(root->right,level+1);
        dfs(root->left,level+1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        dfs(root,0);
        return ans;
       
//         queue<TreeNode*>q;
//         q.push(root);
//         int level=0;
        
//         while(!q.empty()){
//             int sz=q.size();
//             while(sz--){
//                 auto node=q.front();
//                 q.pop();
                
//                 if(ans.size()==level) ans.push_back(node->val);
                
//                 if(node->right) q.push(node->right);
//                 if(node->left) q.push(node->left);
                
                
//             }
//             level++;
//         }
        
//         return ans;
    }
};