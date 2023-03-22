class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        
        vector<vector<pair<int,int>>>graph(n+1);
        int ans=INT_MAX;
        
        for(auto &i:roads){
            graph[i[0]].push_back({i[1],i[2]});       // (node,{child,distance})
            graph[i[1]].push_back({i[0],i[2]});
        }
        
        vector<int>vis(n+1);
        vis[1]=true;
        
        queue<int>q;
        q.push(1);
        
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            
            for(auto &[child,dis]:graph[node]){
                
                ans=min(ans,dis);
                
                if(vis[child]==0){     // if child not visited 
                    q.push(child);     // need to process it
                    vis[child]=1;      // visit it
                }
            }
        }
        return ans;
        
    }
};