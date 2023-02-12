class Solution {
public:
    
    long long ans=0;
    
    long long help(vector<int>adj[],vector<bool>&vis,int seats, int curr_node){
        
        vis[curr_node]=true;
        long long cnt_node=1;
        
     
        for(auto child : adj[curr_node]){
            if(!vis[child])
                cnt_node += help(adj,vis,seats,child);
        }
        
            
            long long temp=cnt_node/seats;
            
            if(cnt_node % (seats)!=0 ) temp++;    // you don't have enough seats (required another car costing 1 more L)
            if(curr_node!=0) ans+=temp;
            
        return cnt_node;           // return the count of nodes upto a particular nodeRishi 
    }
    
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        
        int n=roads.size();
        
        vector<int>adj[n+1];
        vector<bool>vis(n+1,0);
        
        for(auto &vec:roads){
            adj[vec[0]].push_back(vec[1]);
            adj[vec[1]].push_back(vec[0]);
        }
        
        help(adj,vis,seats,0);
        return ans;
    }
};