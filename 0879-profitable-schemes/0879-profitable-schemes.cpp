class Solution {
public:
    
    int help(int n, int mnpr, vector<int>&grp, vector<int>&pr, int idx, long long gained, int people, vector<vector<vector<long long>>>&dp){
        
         if(gained >= mnpr) gained= mnpr;
        if(idx == grp.size() and gained >= mnpr and people <= n) return 1;
        if(people > n or idx >= grp.size()) return 0;
         if(dp[idx][gained][people]!=-1) return dp[idx][gained][people];
        
      
        
        int chori_kar= help(n, mnpr, grp, pr, idx+1, gained+pr[idx], people+grp[idx], dp) % int(1e9+7);
        int chori_mt_kar= help(n, mnpr, grp, pr, idx+1, gained, people, dp) % int(1e9+7);
            
        return dp[idx][gained][people]= (chori_kar + chori_mt_kar) % int(1e9+7);
         
    }
    
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        
            vector<vector<vector<long long>>>dp(group.size()+1,vector<vector<long long>>(minProfit+2,vector<long long>(n+1,-1)));
        return help(n, minProfit, group, profit, 0, 0,0,dp);
    }
};