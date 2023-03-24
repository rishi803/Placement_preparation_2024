class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int> visited(n);
        vector<vector<pair<int,int>>>graph(n);
        queue<int> q;
        q.push(0);
        int ans = 0;
        
        for (auto &i : connections){
            graph[i[0]].push_back({i[1],1});
            graph[i[1]].push_back({i[0],0});     // fake node having value 0 to identify
        }
        
        while (!q.empty()){
            auto curr= q.front();
            q.pop();
            visited[curr] = 1;

            // change dir for all arrows facing out
            for (auto a: graph[curr]){
                if (!visited[a.first]){
                    
                    if(a.second==1)
                    ans++;
                    q.push(a.first);
                }
            }
         
        }
        return ans;
    }
};