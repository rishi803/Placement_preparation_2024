

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if(!root) return nullptr;
        // if(root->val==p->val or root->val==q->val) return root;
        // if(p->val>root->val and q->val>root->val) return lowestCommonAncestor(root->right,p,q);
        // else if(p->val<root->val and q->val<root->val) return lowestCommonAncestor(root->left,p,q);
        // return root;
        
        while(root){
            if(root->val==p->val or root->val==q->val) break;
            else if(p->val>root->val and q->val>root->val) root=root->right;
            else if(p->val<root->val and q->val<root->val) root=root->left;
            else break;
        }
        return root;
    }
};