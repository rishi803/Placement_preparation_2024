
class Solution {
public:
    
    TreeNode* help(string &traversal,int level,int &idx){
        if(idx==traversal.size()) return nullptr;
        
        int currlevel=0;
        while(idx+currlevel<traversal.size() and traversal[idx+currlevel]=='-'){
            currlevel++;         // no. of dashes showing current level
        }
        
        if(currlevel==level){
            
             idx+=currlevel;   // jump over dashes so idx is on digit and it update idx only if level matches                                      // means if and only if we have used this idx for currlevel
            
            int currvalue=0;
            
            while(traversal[idx]>='0' and traversal[idx]<='9'){
                currvalue=currvalue*10 + traversal[idx]-'0';
                idx++;  // after end of while loop this will be at '-'
            }
             
            
            TreeNode* root= new TreeNode(currvalue); // this is root node
             root->left=help(traversal,level+1,idx); // increase level temporary and idx permanently
             root->right=help(traversal,level+1,idx);// update idx from left passed here
            return root;
        }
        
        return nullptr;    
       
    }
    
    TreeNode* recoverFromPreorder(string traversal) {
            
        int idx=0;
        return help(traversal,0,idx);
    }
};