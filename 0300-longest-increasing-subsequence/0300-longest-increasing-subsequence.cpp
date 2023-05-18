class Solution {
public:
    
    int dp[2502][2502];
    
    int help(vector<int>&nums,int idx,int prev){
     if(idx==nums.size()) return 0;
     if(dp[idx][prev+1]!=-1) return dp[idx][prev+1];
        
        int take=0,nottake=0;
        if(prev==-1 or nums[idx]>nums[prev]){
           take=1+help(nums,idx+1,idx); 
        }
         nottake=help(nums,idx+1,prev);
        
        return dp[idx][prev+1]=max(take,nottake);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        
        memset(dp,-1,sizeof(dp));
        return help(nums,0,-1);
    }
    
};