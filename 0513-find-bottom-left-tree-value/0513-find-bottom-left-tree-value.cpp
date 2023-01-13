
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        
        queue<TreeNode*>q;
        q.push(root);
        int ans=root->val;
        while(!q.empty()){
            int sz=q.size();
           int tempsz=sz;
            while(tempsz--){
                auto node=q.front();
                q.pop();
                if(tempsz+1==sz){
                    ans=node->val;            //LEFTMOST node
                }
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return ans;
    }
};