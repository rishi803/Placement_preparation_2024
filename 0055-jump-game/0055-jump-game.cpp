class Solution {
public:
    
    vector<int>dp;
    
    bool help(vector<int>&nums,int idx){
        
        if(idx==nums.size()-1) return true;
        if(idx>=nums.size()) return false;
        if(dp[idx]!=-1) return dp[idx];
        
        for(int i=1;i<=nums[idx];i++){
            
            if (help(nums,idx+i)) return dp[idx]=true;    
        }
        
        return dp[idx]=false;
    }
    bool canJump(vector<int>& nums) {
        
        dp.resize(nums.size(),-1);
        
        return help(nums,0);
    }
};