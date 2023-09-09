class Solution {
public:
    
    int dp[302][301];
    
    long help(int &n, int &x, long sum, int idx){
        
        // cout<<sum;
       
        if(sum == n) return 1;
        if(sum > n) return 0;
         if(idx > n) return 0;
        
        if(dp[sum][idx] != -1) return dp[sum][idx];
        
        long take=0, skip=0;
        
        take+= help(n, x, sum+pow(idx,x), idx+1);
        skip+= help(n, x, sum, idx+1);
        
        return dp[sum][idx]= (skip+take) % (1000000007);
    }
    
    int numberOfWays(int n, int x) {
        
        memset(dp, -1, sizeof(dp));
      
        if(n == 1) return 1;
        return help(n, x, 0, 1);
    }
};