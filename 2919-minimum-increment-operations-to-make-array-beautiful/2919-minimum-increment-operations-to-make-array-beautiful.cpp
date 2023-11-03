class Solution {
public:
    
    vector<long long>dp;
    
    long long help(vector<int>&nums, int k, int idx){
        
        if(idx > nums.size() -3) return 0;
        if(dp[idx] != -1) return dp[idx];
        long long op1= INT_MAX, op2 = INT_MAX, op3= INT_MAX;
        
         op1= max(0, k-nums[idx] )+ help(nums, k, idx+1);
          op2=max(0, k-nums[idx+1]) + help(nums, k, idx+2);
         op3=max(0, k-nums[idx+2]) + help(nums, k, idx+3);
        
        return dp[idx]= min({op1, op2, op3});
    }
    
    long long minIncrementOperations(vector<int>& nums, int k) {
        
        dp.resize(nums.size(),-1);
        return help(nums, k, 0);
    }
};