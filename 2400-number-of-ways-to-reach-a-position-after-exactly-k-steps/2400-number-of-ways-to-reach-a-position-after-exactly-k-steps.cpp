class Solution {
public:
    
    int mod= int(1e9 + 7);
    vector<vector<int>>dp;
    
    int help(int k, int st, int end){
        if(k == 0) return  st == end;
        if(abs(st-end) > k) return 0;
        
        if(dp[k][st+1000] != -1) return dp[k][st+1000];
        
        int op1= help(k-1, st+1, end);
        int op2= help(k-1, st-1, end);
        
        return dp[k][st+1000]= (op1+op2) % mod;

    }
    
    int numberOfWays(int startPos, int endPos, int k) {
        
        dp.resize(k+1,vector<int>(startPos+2001,-1));
        return help(k, startPos, endPos);
    }
};