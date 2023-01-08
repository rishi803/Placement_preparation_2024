class Solution {
public:
    
    bool help(vector<int>&nums,int target,int st,vector<vector<int>>&dp){
        if(st>=nums.size() or target<0) return false;
        if(target==0) return true;
        if(dp[target][st]!=-1) return dp[target][st];
        return dp[target][st]=help(nums,target-nums[st],st+1,dp) or help(nums,target,st+1,dp);
        
    }
    
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int target=sum/2;
        if(2*target!=sum) return false;
        vector<vector<int>>dp(target+1,vector<int>(nums.size()+1,-1));
        return help(nums,target,0,dp);
    }
};