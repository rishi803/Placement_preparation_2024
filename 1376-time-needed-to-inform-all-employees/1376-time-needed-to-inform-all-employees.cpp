class Solution {
public:
    
      int ans=0;
    
    void dfs(int man,vector<int>adj[],int n,int currans,vector<int>&informTime){
         ans=max(ans,currans);
        for(auto child:adj[man]){
            dfs(child,adj,n,currans+informTime[man],informTime);
        }
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
      
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            if(manager[i]!=-1){
                adj[manager[i]].push_back(i);
            }
        }
        
        dfs(headID,adj,n,0,informTime);
        return ans;
    }
};