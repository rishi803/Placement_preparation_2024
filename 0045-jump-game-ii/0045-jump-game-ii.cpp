class Solution {
public:
 vector<long long>dp;
     long long help(int idx,vector<int>&nums){
         
        if(idx>=nums.size()-1) return 0;
         if(nums[idx] == 0) return INT_MAX;
         
        if(dp[idx]!=-1) return dp[idx];
        
        
        long long ans=INT_MAX;
        for(int i=1;i<=nums[idx];i++){
             ans=min(ans,1+help(idx+i,nums));              // we need minimum ans from root to leaf
        }                                             // it give minimum ans at each root from all its below child
         
        //   long long ans=INT_MAX;
        // for(int i=idx+1; i<= (idx + nums[idx]);i++){
        //      ans=min(ans,1+help(i,nums));              // we need minimum ans from root to leaf
        // }          
        
        return dp[idx]=ans;
    }
    int jump(vector<int>& nums) {
        dp.resize(nums.size(),-1);
        return help(0,nums);
    }
};