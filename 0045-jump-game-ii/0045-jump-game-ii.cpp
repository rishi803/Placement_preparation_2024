class Solution {
public:
 vector<long long>dp;
    long long help(int idx,vector<int>&nums){
        if(idx>=nums.size()-1) return 0;
        if(dp[idx]!=-1) return dp[idx];
        
        
        long long ans=INT_MAX;
        for(int i=idx+1;i<=idx+nums[idx];i++){
             ans=min(ans,1+help(i,nums));
        }
        
        return dp[idx]=ans;
    }
    int jump(vector<int>& nums) {
        dp.resize(nums.size(),-1);
        return help(0,nums);
    }
};