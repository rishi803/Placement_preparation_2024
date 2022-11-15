//  DIJIKSTRA---> (only for +ve weight, may work for -ve weigth also but definitely fails for -ve weight cycle)  single source shortest path

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n+1,INT_MAX);         
        vector<vector<int>>adj[n+1];          // 3d vector  adj
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;  // min heap (dist_of_node,node)
        for(int i=0;i<times.size();i++){
            int node=times[i][0];
            int adjnode=times[i][1];
            int weight=times[i][2];
            adj[node].push_back({adjnode,weight});                // adj[node] = ({adjacent_node, weight})
        }
        dist[k]=0;
        pq.push({0,k});
        
        while(!pq.empty()){
            
            int node=pq.top().second;
            pq.pop();
            
            for(auto &adjnode_vector:adj[node]){             
                int adjnode_of_node=adjnode_vector[0];
                int adjnode_weight=adjnode_vector[1];
                
                if(dist[node]+adjnode_weight<dist[adjnode_of_node]){
                    dist[adjnode_of_node]=dist[node]+adjnode_weight;
                    pq.push({dist[adjnode_of_node],adjnode_of_node});
                }
            }
        }
        int ans=0;
            for(int i=1;i<=n;i++){
                if(dist[i]==INT_MAX) return -1;
                ans=max(ans,dist[i]);
            }
            return ans;
        
    }
};