1. tabulation approach (bottom up)
```
int rob(vector<int>& nums) {
vector<int>dp(nums.size());
if(nums.size()==1) return nums[0];
dp[0]=nums[0];
dp[1]=max(nums[0],nums[1]);
for(int i=2;i<nums.size();i++){
dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
}
return dp[dp.size()-1];
}
```
​
2. Two pointers
```
int rob(vector<int>& nums) {
if(nums.size()==1) return nums[0];
int second_last=nums[0];
int last = max(nums[0],nums[1]),ans=last;
for(int i=2;i<nums.size();i++){
ans=max(last,nums[i]+second_last);
second_last=last;
last=ans;
}
return ans;
}
```
3. Recursive dp ( memoization)
​
```
int help(vector<int>&nums,int ind,vector<int>&dp){
if(ind>=nums.size()) return 0;
if(dp[ind]!=-1) return dp[ind];
return dp[ind]=max(nums[ind]+help(nums,ind+2,dp),help(nums,ind+1,dp));
}
int rob(vector<int>& nums) {
vector<int>dp(nums.size()+1,-1);
return help(nums,0,dp);
}
////////////////////////////////////////
class Solution {
public:
vector<vector<int>>dp;
int help(vector<int>&nums,int idx,bool canrob){
if(idx>=nums.size()) return 0;
if(dp[idx][canrob]!=-1) return dp[idx][canrob];
int rob=0,notrob=0;
if(canrob){
rob=nums[idx]+help(nums,idx+1,false);
notrob=help(nums,idx+1,true);