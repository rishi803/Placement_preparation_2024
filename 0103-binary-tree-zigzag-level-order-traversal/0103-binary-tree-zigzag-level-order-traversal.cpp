
class Solution {
public:
    vector<vector<int>>res;
    void help(TreeNode *root,int level){
        if(!root) return;
        if(level>=res.size()) res.push_back({});
        res[level].push_back(root->val);
        help(root->left,level+1);
        help(root->right,level+1);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        help(root,0);
        for(int i=1;i<res.size();i+=2){
            reverse(res[i].begin(),res[i].end());
        }
        
        return res;
        
    }
};