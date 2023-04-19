
class Solution {
public:
    int longest=0;
    
    void help(TreeNode* root,int cnt,bool cangoleft){
          if(root==nullptr) return;
        
        longest=max(longest,cnt);
        
          if(cangoleft){
              help(root->left,cnt+1,false);
              help(root->right,1,true);
          }
        
        else{
            help(root->right,cnt+1,true);
            help(root->left,1,false);
        }
    }
    
    int longestZigZag(TreeNode* root) {
        
        help(root,0,true);
        help(root,0,false);
        
        return longest;
    }
};