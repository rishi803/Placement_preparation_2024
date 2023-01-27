class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);       // vector<vector<dest,cost>>
        for(auto e : flights) {
            graph[e[0]].push_back({e[1], e[2]});
        }
        int ans=INT_MAX;
        vector<int> cost(n, INT_MAX);
        queue<pair<int, int>> q;                       
        q.push({src, 0});                      // q<pair<dest,initial_cost>>
        int stops=0;
        while(stops<=k && !q.empty()) {
            int sz=q.size();
            while(sz--) {
                int cur_node=q.front().first;
                int cur_cost=q.front().second;
                q.pop();
                if(cur_cost>cost[cur_node]) continue;
                cost[cur_node]=cur_cost;
                for(auto &child : graph[cur_node]) {
                    if(child.second+cur_cost>ans) continue;
                    if(child.first==dst) ans=min(ans, child.second+cur_cost);
                    q.push({child.first, child.second+cur_cost});
                }
            }
            stops++;
        }
        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};