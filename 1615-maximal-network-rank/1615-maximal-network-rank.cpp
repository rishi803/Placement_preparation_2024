class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>adj[n];
        unordered_map<int,vector<int>>mp;
        
        for(auto e: roads){
            mp[e[0]].push_back(e[1]);
            mp[e[1]].push_back(e[0]);
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        int ans= INT_MIN;
        
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                
                int temp=0;
                
                if(find(mp[i].begin(), mp[i].end(),j) != mp[i].end() or find(mp[j].begin(), mp[j].end(),i) != mp[j].end()){
                    temp+= adj[i].size();
                    temp+= adj[j].size();
                    temp--;
                }
                else{
                    temp+= adj[i].size();
                    temp+= adj[j].size();
                }
                ans= max(ans,temp);
            }
        }
        
        return ans;
        
        
    }
};