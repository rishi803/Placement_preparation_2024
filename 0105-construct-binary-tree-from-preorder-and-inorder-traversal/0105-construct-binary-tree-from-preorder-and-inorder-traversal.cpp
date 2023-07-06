
class Solution {
public:
    
    int idx=0;
    
    TreeNode* help(vector<int>&preorder,vector<int>&inorder,int st,int end){
         
        if(st>end) return nullptr;
        
       
        int temp=st;
        while(preorder[idx]!=inorder[temp]) temp++;
        idx++;
         TreeNode* root= new TreeNode(inorder[temp]);
        root->left=help(preorder,inorder,st,temp-1);
        root->right=help(preorder,inorder,temp+1,end);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       
        return help(preorder,inorder,0,preorder.size()-1);
    }
};