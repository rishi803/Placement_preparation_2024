class Solution {
public:
    
    // int tsum;
    
    int dp[1001][51];
    
    int help(vector<int>&nums,int k,int idx){
         
        if(k==0 and idx==nums.size()) return 0;
        if(idx==nums.size() or k==0) return INT_MAX;
        if(dp[idx][k]!=-1) return dp[idx][k];
        
        int mx=INT_MAX,sum=0;
        
        for(int i=idx;i<nums.size();i++){
            mx=min(mx,max(sum+=nums[i],help(nums,k-1,i+1)));
        }
        
        return dp[idx][k]=mx;
    }
    
    int splitArray(vector<int>& nums, int k) {
        
        memset(dp,-1,sizeof(dp));
        // tsum=accumulate(nums.begin(),nums.end(),0);
        return help(nums,k,0);
    }
};