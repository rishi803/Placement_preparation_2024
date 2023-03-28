class Solution {
public:
    int help(vector<int>&days,vector<int>&costs,int idx,vector<int>&dp){
        
        if(idx>=days.size()) return 0;
        
        int cost_days=costs[0]+help(days,costs,idx+1,dp);
        if(dp[idx]!=-1) return dp[idx];
        
        int st_idx=idx;
        
        while(st_idx<days.size() and days[st_idx]<days[idx]+7) st_idx++;
        
        int cost_week=costs[1]+help(days,costs,st_idx,dp);
        
        while(st_idx<days.size() and days[st_idx]<days[idx]+30) st_idx++;
        
        int cost_month=costs[2]+help(days,costs,st_idx,dp);
        
        return dp[idx]=min({cost_days,cost_week,cost_month});
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(days.size()+1,-1);
        return help(days,costs,0,dp);
    }
};