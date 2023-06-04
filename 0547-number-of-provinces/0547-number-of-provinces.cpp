class Solution {
public:
    
     void dfs(int i,vector<int>adj[],vector<int>&vis){
         vis[i]=true;
         for(auto child:adj[i]){
             if(!vis[child])
             dfs(child,adj,vis);
         }
     }
    int findCircleNum(vector<vector<int>>& M) { 
       
        int n=M.size();
         int ans=0;
        
        vector<int>adj[n],vis(n);
        //making group
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(M[i][j]==1 and i!=j)  {
                    adj[i].push_back(j);
                }
            }
        }
        
       for(int i=0;i<n;i++){
           if(!vis[i]){
               // cout<<i<<endl;
           ans++;
           dfs(i,adj,vis);    
           } 
       }
        return ans;
    }
};