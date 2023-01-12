/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // int i=0;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
     
      if(!root or root==p or root==q) return root;
     
       TreeNode* l= lowestCommonAncestor(root->left,p,q);
       TreeNode* r= lowestCommonAncestor(root->right,p,q);
        // i++;
        //    if(root) cout<<" i= "<<i<<" val= "<<root->val<<endl;
        // if(!l and r) cout<<"null "<<r->val<<" i= "<<i<<endl;
        // if(l and !r) cout<<l->val<<" null"<<" i= "<<i<<endl;
        // if(!l and !r) cout<<"null null"<<" i= "<<i<<endl;
        // if(l and r)
        // cout<<l->val<<" "<<r->val<<" i= "<<i<<endl;
       if(l and r) return root;
        if(!l) return r;
         return l;
    }
};