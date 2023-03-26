class Solution {
public:
    
    int mx=-1;
    
    void help(int i,vector<int>&edges,vector<int>&dp,int &cnt,vector<int>&vis,vector<bool>&inRecursion){
        
        if(i==-1) return;
        cnt++;
        
        if(vis[i]==1 and inRecursion[i]==1){
            dp[i]=cnt-dp[i];
            mx=max(dp[i],mx);
            return;
        }
        if(vis[i]==1) return;
        
        dp[i]=cnt;
        
        vis[i]=1;
        inRecursion[i]=1;
        
             
         help(edges[i],edges,dp,cnt,vis,inRecursion);
        inRecursion[i]=0;
        
    }
    
    int longestCycle(vector<int>& edges) {
        
        int sz=edges.size();
        vector<int>vis(sz);
         vector<int>dp(sz);
        vector<bool>inRecursion(sz);
        
        for(int i=0;i<sz;i++){
            
            if(edges[i]==-1) continue;
            
            if(!vis[i]){
               
                int cnt=0;
                help(i,edges,dp,cnt,vis,inRecursion);
                // if(sz-(cnt+i)<=mx) break;
            }
        }
        
        return mx;
    }
};