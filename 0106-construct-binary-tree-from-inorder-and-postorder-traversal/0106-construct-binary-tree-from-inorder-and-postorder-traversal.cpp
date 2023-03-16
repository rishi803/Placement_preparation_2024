
class Solution {
public:
    int idx=0;
    
    TreeNode* help(vector<int>&in,vector<int>&post,int st,int end){
       if(st>end) return nullptr;
        
        int pivot=end;
        
        while(in[pivot]!=post[idx]) pivot--;
        
        idx--;
        
        TreeNode* node=new TreeNode (in[pivot]);
        node->right= help(in,post,pivot+1,end);
        node->left= help(in,post,st,pivot-1);
        
            
        return node;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        idx=postorder.size()-1;
        return help(inorder,postorder,0,idx);
    }
};