class Solution {
public:
    
    int mx=-1;
    
    void help(int i,vector<int>&edges,vector<int>&dp,vector<int>&vis,int prev,vector<bool>&inRecursion){
        
        if(i==-1){
        return;}
        
        
        if(vis[i]==1 and inRecursion[i]==1){
            dp[i]=dp[prev]-dp[i]+1;
            mx=max(dp[i],mx);
            return;
        }
        if(vis[i]==1) return;
        
        
        if(prev!=-1)
        dp[i]=dp[prev]+1;
        
        vis[i]=1;
        inRecursion[i]=1;
             
         help(edges[i],edges,dp,vis,i,inRecursion);
        inRecursion[i]=0;
    }
    
    int longestCycle(vector<int>& edges) {
        
        int sz=edges.size();
        vector<int>vis(sz);
        vector<int>dp(sz,1);
         vector<bool>inRecursion(sz);
        
        for(int i=0;i<sz;i++){
            
            if(edges[i]==-1) continue;
            
            if(!vis[i]){
               
                
                help(i,edges,dp,vis,-1,inRecursion);
       
            }
        }
        
        return mx;
    }
};