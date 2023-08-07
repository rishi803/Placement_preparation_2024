
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        
        if(!root) return nullptr;
        
        if(root->val >= low and root->val <= high ){
            root->left= trimBST(root->left, low, high);
            root->right= trimBST(root->right, low, high);     
        }
        
        else if( root->val < low ) return trimBST(root->right, low, high);
        
        else return trimBST(root->left, low, high);
        
        return root;
    }
};