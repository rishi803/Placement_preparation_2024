
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            auto f=q.front();
            // cout<<f->val<<endl;
            q.pop();
            if(f->left) q.push(f->left);
            if(f->right) q.push(f->right);
            swap(f->left,f->right);
        }
        return root;
    }
};