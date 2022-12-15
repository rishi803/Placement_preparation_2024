
class Solution {
public:
    unordered_map<TreeNode*,vector<int>>mp;
    int help(TreeNode* root,bool valid){
        if(!root) return 0;
        if(mp.count(root) and mp[root][valid]!=-1) return mp[root][valid];
        mp[root]={-1,-1};
        int rob = valid?root->val+help(root->left,false)+help(root->right,false):-1;
        int notrob=help(root->left,true)+help(root->right,true);
        return mp[root][valid]= max(rob,notrob);
    }
    
    int rob(TreeNode* root) {
        
        return help(root,true);
    }
};