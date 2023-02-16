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
        }
        else{
           notrob= help(nums,idx+1,true);
        }
        
        return dp[idx][canrob]=max(rob,notrob);
    }
    
    int rob(vector<int>& nums) {
        dp.resize(nums.size(),vector<int>(2,-1));
        return help(nums,0,true);
    }
};