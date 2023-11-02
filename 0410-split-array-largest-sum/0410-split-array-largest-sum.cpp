class Solution {
public:
    
   int dp[1002][51];
    
    int help(vector<int>&nums, int k, int idx){
        
         if(k == 0 or idx >= nums.size()-1) return 0;
        
         if(k == 1){
           return accumulate(nums.begin()+idx, nums.end(), 0);
        }
     
        if(dp[idx][k] != -1) return dp[idx][k];
       
        int sum= 0, ans= INT_MAX;
        
        for(int i= idx; i<nums.size()-1; i++){
            sum+= nums[i];
            int mn= max(sum, help(nums, k-1, i+1));
            ans= min(ans, mn);
        }
        
        return dp[idx][k]= ans;
        
    }
    
    int splitArray(vector<int>& nums, int k) {
        
        memset(dp, -1, sizeof(dp));
        return help(nums, k, 0);
    }
};