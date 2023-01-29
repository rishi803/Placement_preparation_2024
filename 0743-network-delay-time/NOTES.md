if (dist[u] != INT_MAX && dist[v] > dist[u] + w) {
dist[v] = dist[u] + w;
}
}
}
​
int maxwait = 0;
for (int i = 1; i <= N; i++)
maxwait = max(maxwait, dist[i]);
return maxwait == INT_MAX ? -1 : maxwait;
}
* ******dijkstra algo********
```
//  DIJKSTRA---> (only for +ve weight, may work for -ve weigth also but definitely fails for -ve weight cycle)  single source shortest path
​
class Solution {
public:
int networkDelayTime(vector<vector<int>>& times, int n, int k) {
vector<int>dist(n+1,INT_MAX);
vector<vector<int>>adj[n+1];          // 3d vector  adj
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;  // min heap (dist_of_node,node)
for(int i=0;i<times.size();i++){
int node=times[i][0];
int adjnode=times[i][1];
int weight=times[i][2];
adj[node].push_back({adjnode,weight});                // adj[node] = ({adjacent_node, weight})
}
dist[k]=0;
pq.push({0,k});
while(!pq.empty()){
int node=pq.top().second;
pq.pop();