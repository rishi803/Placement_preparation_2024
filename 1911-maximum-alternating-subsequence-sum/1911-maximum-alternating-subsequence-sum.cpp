// you have two choices always


class Solution {
public:
    vector<vector<long long>>dp;
    
    long long help(vector<int>&nums,int idx,bool flag){
        
        if(idx>=nums.size()) return 0;
        if(dp[idx][flag]!=-1) return dp[idx][flag];
        long long take=0,nottake=0;
        
        if(flag){
             take=nums[idx]+help(nums,idx+1,false); // if prev element not added then add this
            nottake=help(nums,idx+1,true);          // if prev not added and this also not added
        }
        else{
            take=-nums[idx]+help(nums,idx+1,true); // if prev element is added then subtract this
            nottake=help(nums,idx+1,false);        // if prev element is added then dont subtract this
        }
        
        return dp[idx][flag]=max(take,nottake);
        
    }
    
    long long maxAlternatingSum(vector<int>& nums) {
        dp.resize(nums.size(),vector<long long>(2,-1));
        return help(nums,0,true);
    }
};