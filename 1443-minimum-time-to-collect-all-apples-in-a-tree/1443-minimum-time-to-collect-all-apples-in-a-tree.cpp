class Solution {
public:
    int dfs(int cur,vector<bool>&hasApple,vector<vector<int>>&adj,int parent){
        int time=0;
        
        for(int &child:adj[cur]){
            if(child==parent) continue;
            
            int time_from_child=0;
                time_from_child=dfs(child,hasApple,adj,cur);
            
            if(time_from_child>0 or hasApple[child]){
                time+=time_from_child+2;
            }
        }
        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
       int ans=0;
        vector<vector<int>>adj(n);
        
        for(auto &it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        return dfs(0,hasApple,adj,-1);
    }
};