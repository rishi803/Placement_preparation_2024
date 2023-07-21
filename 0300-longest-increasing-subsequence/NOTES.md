[1,3,6,7,9,4,10,5,6]
​
1.. TLE
​
vector<vector<int>>dp;
int help(int prev,int idx,vector<int>&nums,vector<vector<int>>&dp){
if(idx>=nums.size()) return 0;
if(dp[idx][prev+1]!=-1) return dp[idx][prev+1];
int take=0;
if(prev==-1 or nums[idx]>nums[prev]) take=1+help(idx,idx+1,nums,dp);
int not_take=help(prev,idx+1,nums,dp);
return dp[idx][prev+1] =max(take,not_take);
}
int lengthOfLIS(vector<int>& nums) {
vector<vector<int>>dp(nums.size(),vector<int>(nums.size()+1,-1));
return help(-1,0,nums,dp);
}
​
2.. Space optimized memoization
​
int help(int prev,int idx,vector<int>&nums,vector<int>&dp){
if(idx>=nums.size()) return 0;
if(dp[prev+1]!=-1) return dp[prev+1];
int take=0;
if(prev==-1 or nums[idx]>nums[prev]) take=1+help(idx,idx+1,nums,dp);
int not_take=help(prev,idx+1,nums,dp);
return dp[prev+1] =max(take,not_take);
}
int lengthOfLIS(vector<int>& nums) {
vector<int>dp(nums.size()+1,-1);
return help(-1,0,nums,dp);
}
3..