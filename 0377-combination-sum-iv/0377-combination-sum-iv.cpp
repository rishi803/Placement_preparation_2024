class Solution {
public:
    
    vector<vector<int>>dp;
    
    int help(vector<int>&nums, int target, int idx){
        
        if(idx >= nums.size()) return 0;
        if(target < 0) return 0;
        if(target == 0) return 1;
        if(dp[idx][target] != -1) return dp[idx][target];
        int ways= 0;
        
        for(int i=0; i<nums.size(); i++){
            ways += help(nums, target-nums[i], i);
        }
        
        return dp[idx][target]= ways;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        
        dp.resize(nums.size()+1, vector<int>(target+1, -1));
        return help(nums, target, 0);
    }
};