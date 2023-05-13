class Solution {
public:
    
    int help(int target,int z,int o,vector<int>&dp){
        if(target==0){ return 1;}
        if(target<0) return 0;
        if(dp[target]!=-1) return dp[target];
        long long ans=(help(target-z,z,o,dp)%(int(1e9+7))+help(target-o,z,o,dp)%(int(1e9+7)))%(int(1e9+7));
        
        return dp[target]=ans;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        
        int result=0;
        vector<int>dp(high+1,-1);
        for(int i=low;i<=high;i++){
            result=(result%(int(1e9+7))+(help(i,zero,one,dp))%(int(1e9+7)))%(int(1e9+7));
        }
        return result;
    }
};