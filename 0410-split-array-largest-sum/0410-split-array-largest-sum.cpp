class Solution {
public:
    int dp[1001][51];
    int help(vector<int>&nums,int cut,int idx){
        if(idx==nums.size() and cut==0) return 0;
        if(idx==nums.size() or cut==0) return INT_MAX;
        if(dp[idx][cut]!=-1)
            return dp[idx][cut];
        int currsum=0,ans=INT_MAX,nextsum=0;
        
        for(int i=idx;i<nums.size();i++){
            currsum+=nums[i];
            nextsum=help(nums,cut-1,i+1);
            
            ans=min(ans,max(currsum,nextsum));
        }
        
        return dp[idx][cut]= ans;
    }
    int splitArray(vector<int>& nums, int k) {
           memset(dp,-1,sizeof(dp));
        return help(nums,k,0);
    }
};