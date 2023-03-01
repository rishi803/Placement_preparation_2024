class Solution {
public:
    int ans=INT_MAX;
    vector<pair<int,int>>adj[100];

int dijkstra(int src, int n, int threshold) {
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  // min heap
    int count=0;
    dist[src]=0;
    vector<bool>vis(n,false);
    
    pq.push({src,0});
    
    while(!pq.empty()){
        
        int from=pq.top().first;
        int from_wt=pq.top().second;
        pq.pop();
        vis[from]=true;
        
        if(from_wt>threshold) continue;
        
        for(auto &[to,to_wt]:adj[from]){
            
            if(dist[to]!=INT_MAX and dist[from]+to_wt<dist[to]){
                dist[to]=dist[from]+to_wt;
                 pq.push({to,dist[to]});
            }
            else if(dist[to]!=INT_MAX and dist[from]+to_wt>=dist[to]) continue;
            
           else if(dist[from]+to_wt<=threshold and !vis[to]){
                dist[to]=dist[from]+to_wt;
                count++;
               
                pq.push({to,dist[to]});
                // cout<<to<<" "<<dist[to]<<endl;
            }
        }
        
        
    }
    
   
    

    return count;
}

int findTheCity(int n, vector<vector<int>>& edges, int threshold) {
    // Step 1: Build the graph
    for (auto e : edges) {
        int u = e[0], v = e[1], w = e[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int res=-1;

    // Step 2: Use Dijkstra's algorithm
    vector<int>ans;
   for(int i=0;i<n;i++){
       int temp=dijkstra(i,n,threshold);
       // cout<<endl;
       ans.push_back(temp);
   }
    int mn=*min_element(ans.begin(),ans.end());
    
    for(int i=0;i<ans.size();i++){
        if(ans[i]==mn){
            res=i;
        }
    }

    return res;
}
};