class Solution {
public:
    
    typedef long long int ll;
    
    int cnt=1;
    
    void help(int node,vector<int>adj[],vector<bool>&vis){
        vis[node]=true;
        
        for(auto child:adj[node]){
            if(!vis[child]){
                cnt++;
                help(child,adj,vis);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int sz=bombs.size();
        vector<int>adj[sz];
       for(int i=0;i<sz;i++) {
            ll x1,y1,r1;
            x1=bombs[i][0];
            y1=bombs[i][1];
            r1=bombs[i][2];
            for(int j=0;j<sz;j++) {
                if(i!=j) {
                    ll x,y;
                    x=abs(x1-bombs[j][0]);
                    y=abs(y1-bombs[j][1]);
                    if(x*x+y*y<=r1*r1)
                        adj[i].push_back(j);
                }
            }
        }
        
        int ans=0;
        
        for(int i=0;i<sz;i++){
            vector<bool>vis(sz,false);
            cnt=1;
            help(i,adj,vis);
            ans=max(ans,cnt);
        }
        
        return ans;
    }
};