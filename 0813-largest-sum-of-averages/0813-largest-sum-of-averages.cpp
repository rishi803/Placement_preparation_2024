class Solution {
public:
    
    vector<vector<double>>dp;
    
    double help(vector<int>&nums,int k,int idx){
       
        if(idx>=nums.size()) return 0;
        if(k==0) return -1e8;
        if(dp[idx][k]!=-1) return dp[idx][k];
        
        double ans=-1e8;
        double sum=0;
        
        for(int i=idx;i<nums.size();i++){
            sum+=nums[i];
            ans=max(ans,(sum)/(i-idx+1)+help(nums,k-1,i+1));
        }
        
        return dp[idx][k]=ans;
        
    }
    double largestSumOfAverages(vector<int>& nums, int k) {
    
        dp.resize(nums.size()+1,vector<double>(nums.size()+1,-1));
    
      return help(nums,k,0);
      
    }
};