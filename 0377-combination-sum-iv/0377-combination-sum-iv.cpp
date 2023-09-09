class Solution {
public:
    
    vector<int>dp;
    
    int help(vector<int>&nums, int target){
    
        if(target < 0) return 0;
        if(target == 0) return 1;
        if(dp[target] != -1) return dp[target];
        int ways= 0;
        
        for(int i=0; i<nums.size(); i++){
            ways += help(nums, target-nums[i]);
        }
        
        return dp[target]= ways;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        
        dp.resize(target+1, -1);
        return help(nums, target);
    }
};