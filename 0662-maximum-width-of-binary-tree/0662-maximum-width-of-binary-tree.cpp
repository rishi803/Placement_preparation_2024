
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        
        queue<pair<TreeNode*,size_t>>q;
        size_t ans=0;
        q.push({root,0});
        
        while(!q.empty()){
            
            size_t first=q.front().second;
            size_t last=q.back().second;
            
            ans=max(ans,last-first+1);
            int sz=q.size();
            
            while(sz--){
                auto [node,ind]=q.front();
                q.pop();
                
                if(node->left){
                    q.push({node->left,2*ind+1});
                }
                
                if(node->right){
                    q.push({node->right,2*ind+2});
                }
            }
        }
        
        return ans;
    }
};