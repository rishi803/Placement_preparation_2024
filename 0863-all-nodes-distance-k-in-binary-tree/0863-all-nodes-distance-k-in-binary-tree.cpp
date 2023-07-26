////// CONVERT IN GRAPH, THEN SIMPLY FIND NODE AT DISTANCE K

class Solution {
public:
    vector<int>ans;
    unordered_map<int,bool>vis;
    void help(unordered_map<int,vector<int>>&mp,int node,int k){
        
        if(vis[node]) return;
        if(k==0){
            ans.push_back(node);
            return;
        }
        vis[node]=true;
        // cout<<k<<endl;
        for(auto child:mp[node]){
            help(mp,child,k-1);
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int,vector<int>>mp;
        
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            auto f=q.front();
            q.pop();
            
            if(f->left){
                q.push(f->left);
                mp[f->val].push_back(f->left->val);
                mp[f->left->val].push_back(f->val);
            }
            if(f->right){
                q.push(f->right);
                mp[f->val].push_back(f->right->val);
                mp[f->right->val].push_back(f->val);
            }
        }
        
        help(mp,target->val,k);
        
        return ans;
        
    }
};