class Solution {
public:
    
    int dp[366];
    
    int help(vector<int>&days,vector<int>&costs,int idx){
        if(idx>=days.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int cost1day=INT_MAX;
        int cost7day=INT_MAX;
        int cost30day=INT_MAX;
        
        
        cost1day=costs[0]+help(days,costs,idx+1);
        
        
        int i=idx;
        
        while(i<days.size() and days[i]<=days[idx]+6) i++;
        
        cost7day=costs[1]+help(days,costs,i);
        
        int j=idx;
        
        while(j<days.size() and days[j]<=days[idx]+29) j++;
        
        cost30day=costs[2]+help(days,costs,j);
        
        return dp[idx]=min({cost1day,cost7day,cost30day});
        
        
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        memset(dp,-1,sizeof(dp));
        return help(days,costs,0);
    }
};