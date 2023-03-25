class Solution {
public:
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        
        vector<int>adj[n];
        vector<int>nodes;
        vector<int>visited(n);
        int comp=0;
        long long ans=0;
          long long prev_nodes=0;
        for(auto &i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        queue<int>q;
        
        for(int i=0;i<n;i++){
            
        if(!visited[i]) q.push(i);
            
        if(visited[i]) continue;
            
        long long total_nodes=0;
      
        
        while(!q.empty()){
            
             auto f=q.front();
             q.pop();
            
            if(!visited[f])   total_nodes++;
             visited[f]=1;
             
            for(auto &it:adj[f]){
                if(!visited[it]) q.push(it);
            }
            
          
            
          }
         
            if(prev_nodes!=0){
                ans+=prev_nodes*total_nodes;
            }
            prev_nodes+=total_nodes;
            
       }
        return ans;
    }
};