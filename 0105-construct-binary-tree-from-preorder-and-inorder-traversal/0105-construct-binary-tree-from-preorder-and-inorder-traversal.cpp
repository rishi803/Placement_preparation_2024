
class Solution {
public:
    int idx=0;
    
    TreeNode* help(vector<int>&pre,vector<int>&in,int st,int end){
        
        if(st>end) return nullptr;
        
        int pivot=st;
        while(pre[idx]!=in[pivot]) pivot++;
        idx++;
        
        TreeNode* node=new TreeNode (in[pivot]);
        node->left= help(pre,in,st,pivot-1);
        node->right=help(pre,in,pivot+1,end);
            
        return node;
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        return help(preorder,inorder,0,preorder.size()-1);
    }
};