
class Solution {
public:
    
    TreeNode* help(string &traversal, int &idx, int level){
        
        if(idx >= traversal.size()) return nullptr;
       
        int cntdash= 0;
        
        while(traversal[idx+cntdash] == '-') cntdash++;
        
        if(cntdash == level){
            idx+=cntdash;
            
            int digit= 0;
            
            while(traversal[idx] >= '0' and traversal[idx] <= '9') digit= digit*10 + traversal[idx++]-'0';
            
            TreeNode* root= new TreeNode(digit);
            root->left=  help(traversal, idx, level+1);
            root->right= help(traversal, idx, level+1);
             
            return root;
         
        }
        else
        return nullptr;
    }
    
    TreeNode* recoverFromPreorder(string traversal) {
        
        int idx=0;
        return help(traversal, idx, 0);
    }
};