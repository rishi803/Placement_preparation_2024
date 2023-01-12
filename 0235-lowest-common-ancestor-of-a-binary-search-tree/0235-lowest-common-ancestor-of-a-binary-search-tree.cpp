

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        if(root->val==p->val or root->val==q->val) return root;
        if(p->val>root->val and q->val>root->val) return lowestCommonAncestor(root->right,p,q);
        else if(p->val<root->val and q->val<root->val) return lowestCommonAncestor(root->left,p,q);
        return root;
    }
};