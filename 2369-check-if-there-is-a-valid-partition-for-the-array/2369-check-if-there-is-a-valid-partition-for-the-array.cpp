class Solution {
public:
    
    vector<int>dp;
    
    bool help(vector<int>&nums, int idx){
        
        if(idx >= nums.size()) return true;
        if(dp[idx] != -1) return dp[idx];
        
        if(idx+1 < nums.size() and nums[idx] == nums[idx+1]){
            if( help(nums, idx+2) ) return dp[idx]= true;
        }
        
        if(idx+2 < nums.size() and nums[idx] == nums [idx+1] and nums[idx] == nums[idx+2]){
            if( help(nums, idx+3) ) return dp[idx]= true;
        }
        
        if(idx+2 < nums.size() and nums[idx] == nums[idx+1]-1 and nums[idx] == nums[idx+2]-2){
            if( help(nums, idx+3) ) return dp[idx]= true;
        }
        
        return dp[idx]= false;
        
    }
    
    bool validPartition(vector<int>& nums) {
        
        dp.resize(nums.size(), -1);
        return help(nums, 0);
           
    }
};