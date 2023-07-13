class Solution {
public:
    
    bool cycle(vector<int>adj[],int node,vector<bool>&vis,vector<bool>&inrec){
        vis[node]=true;
        inrec[node]=true;
        for(auto child:adj[node]){
            if(!vis[child] and cycle(adj,child,vis,inrec)) return true;
            else if(inrec[child]==true) return true;
        }
        
        inrec[node]=false;
        return false;
    }
    
    bool canFinish(int n, vector<vector<int>>& pre) {
        
        vector<int>adj[n];
        for(auto vec:pre){
            adj[vec[1]].push_back(vec[0]);
        }
        
        vector<bool>vis(n),inrec(n);
        
        for(auto i=0;i<n;i++){
            if(!vis[i]){
                if(cycle(adj,i,vis,inrec)) return false;
            }
        }
        
        return true;
    }
};