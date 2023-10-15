class Solution {
public:
    
    const int mod= int (1e9+7);
    
    int help(int steps, int sz, int idx, vector<vector<int>>&dp){
        
        if(idx >= sz or idx < 0) return 0;
        if(steps < (idx)) return 0;
        if(idx == 0 and steps == 0) return 1;
        if(steps == 0) return 0;
        if(dp[steps][idx] != -1) return dp[steps][idx];
        
        int left= help(steps-1, sz, idx-1, dp) % mod;
        int right= help(steps-1, sz, idx+1, dp) % mod;
        int stay= help(steps-1, sz, idx, dp) % mod;
        
        return dp[steps][idx]= ((left + right) % mod + stay)%mod;
        
    }
    
    int numWays(int steps, int arrLen) {
        
        vector<vector<int>>dp(steps+1, vector<int>(steps+1,-1));
        return help(steps, arrLen, 0, dp);
    }
};