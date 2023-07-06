
class Solution {
public:
    
    int idx=0;
    unordered_map<int,int>mp;
    
    TreeNode* help(vector<int>&preorder,vector<int>&inorder,int st,int end){
         
        if(st>end) return nullptr;
         int temp=idx;
        idx++;
         TreeNode* root= new TreeNode(preorder[temp]);
        root->left=help(preorder,inorder,st,mp[preorder[temp]]-1);
        root->right=help(preorder,inorder,mp[preorder[temp]]+1,end);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return help(preorder,inorder,0,preorder.size()-1);
    }
};