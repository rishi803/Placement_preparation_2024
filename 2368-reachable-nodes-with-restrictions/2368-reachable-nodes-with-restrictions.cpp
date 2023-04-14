class Solution {
public:
    // unordered_map<int,int>cant_visit;
    int cnt=0;
    void help(int parent,vector<int> adj[],vector<bool>&vis){
        
        vis[parent]=true;
        cnt++;
        for(auto child:adj[parent]){
            if(vis[child]) continue;
            
            else{
                help(child,adj,vis);
            }
        }
        
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        
        vector<int> adj[n]; // adjency list
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
      vector<bool>vis(n);
        for(int i:restricted){
            vis[i]=true;
        }
        
     help(0,adj,vis);
        return cnt;
    }
};