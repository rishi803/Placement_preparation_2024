
class Solution {
public:
    int idx=0;
    
    TreeNode* help(vector<int>&in,vector<int>&post,int st,int end){
       if(st>end) return nullptr;
        
        int pivot=st;
        
        while(in[pivot]!=post[idx]) pivot++;  // search this last element in inorder to split it in left and right
        
      
        
        TreeNode* node=new TreeNode (post[idx]);   // always make last element as root element (postorder array)
          idx--;
          node->right= help(in,post,pivot+1,end);
        node->left= help(in,post,st,pivot-1);
      
        
        
            
        return node;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        idx=postorder.size()-1;
        return help(inorder,postorder,0,idx);
    }
};