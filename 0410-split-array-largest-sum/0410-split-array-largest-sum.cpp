class Solution {
public:
    
    int dp[1001][51];
    
    int help(vector<int>&nums, int k, int idx){
        
        if(k < 0) return INT_MAX;
        if(idx >= nums.size() and k==0) return 0;
        if(idx >= nums.size()) return INT_MAX;
        if(dp[idx][k] != -1) return dp[idx][k];
        
        int ans= INT_MAX, currsum= 0;
        
        for(int i=idx; i<nums.size(); i++){
            currsum+= nums[i];
            int nextsum= help(nums, k-1, i+1);
            
            ans= min(ans, max(currsum, nextsum));
        }
        
        return dp[idx][k]= ans;
    }
    int splitArray(vector<int>& nums, int k) {
        
        // dp.resize(nums.size(), vector<int>(k+1,-1));
        memset(dp, -1, sizeof(dp));
         return help(nums, k, 0);
    }
};