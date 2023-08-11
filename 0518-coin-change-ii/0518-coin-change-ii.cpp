class Solution {
public:
    
      vector<vector<int>>dp;
    
    int help(vector<int>&coins, int target, int idx){
        
        if(target == 0) return 1;
        if(idx <0) return 0;
        if(target < 0) return 0;
        if(dp[idx][target] != -1) return dp[idx][target];
        
        int ans=0;
        
        for(int i=idx; i>=0; i--){
            // cout<<"i ="<<i<<" "<<target<<" ";
            ans+= help(coins, target-coins[i], i);
        }
        // cout<<endl;
        
        return dp[idx][target]= ans;
    }
    
    int change(int amount, vector<int>& coins) {
        dp.resize(coins.size(), vector<int>(amount+1,-1));
        return help(coins, amount, coins.size()-1);
    }
};