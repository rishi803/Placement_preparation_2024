class Solution {
public:
    int numSquares(int n) {
        
        vector<int>dp(n+1);
        iota(dp.begin(),dp.end(),0);
        for(int i=4;i<=n;i++){
            
            for(int j=1;j*j<=n;j++){
                if(i-(j*j)>=0){                            
                    dp[i]=min(dp[i],1+dp[i-(j*j)]);  // need to check at every ps breakpoints 
                }
            }
        }
        return dp[n];
    }
};