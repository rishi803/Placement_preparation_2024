class Solution {
public:
    vector<int>cant_go;
    int cnt=0;
    
    void help(int parent,vector<int> adj[]){
        
       cant_go[parent]=1;
        cnt++;
        for(auto child:adj[parent]){
            if(cant_go[child]) continue;
            
            else{
                help(child,adj);
            }
        }
        
        
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        cant_go.resize(n,false);
        vector<int> adj[n]; // adjency list
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
      
        for(int i:restricted){
            cant_go[i]=1;
        }
        
       help(0,adj);
        return cnt;
       
    }
};