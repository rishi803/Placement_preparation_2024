class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int ans=0;
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto &time:times){
            adj[time[0]].push_back({time[1],time[2]});   // adj[from].push_back(to,weight)
        }
        
        vector<int>dis(n+1,INT_MAX);
        dis[k]=0;
        
        priority_queue<int,vector<int>,greater<int>>pq;  // min heap (dist_of_node,node)
        pq.push(k);      // pq({src,dis})
        
        while(!pq.empty()){
            int node=pq.top();
            pq.pop();
            
            for(auto &[child_node,child_weight]:adj[node]){
                if(dis[node]+child_weight<dis[child_node]){
                    dis[child_node]=dis[node]+child_weight;
                     pq.push(child_node);
                }
               
            }
        }
        
        for(int i=1;i<dis.size();i++){
            if(dis[i]==INT_MAX) return -1;
            else ans=max(ans,dis[i]);
        }
        return ans;
    }
};