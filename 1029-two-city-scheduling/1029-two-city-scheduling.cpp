class Solution {
public:
    
    int dp[101][5001];
    
    int help(int idx, vector<vector<int>>&costs, int ap, int bp, int n){
        
        if(ap > n/2 or bp > n/2) return INT_MAX-1000;
        if(idx >= costs.size()) return 0;
        if(dp[idx][ap] != -1) return dp[idx][ap];
        
        int takea= costs[idx][0] + help(idx+1, costs, ap+1, bp, n);
        int takeb= costs[idx][1] + help(idx+1, costs, ap, bp+1, n);
            
        return dp[idx][ap]= min(takea, takeb);
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        memset(dp, -1, sizeof(dp));
        return help(0, costs, 0, 0, costs.size());
    }
};