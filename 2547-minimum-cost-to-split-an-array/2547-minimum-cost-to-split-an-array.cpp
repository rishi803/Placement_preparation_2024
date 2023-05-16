// split array largest sum dp version

class Solution {
public:
    
    int dp[1005];
    int help(vector<int>&nums,int k,int idx){
        if(idx>=nums.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        
        int ans=INT_MAX;
        vector<int>freq(nums.size());     // unordered_map<int,int>freq;
        int trimmed=0;
        
        for(int i=idx;i<nums.size();i++){
            freq[nums[i]]++;
            if(freq[nums[i]]==2) trimmed+=2;
            else if(freq[nums[i]]>2) trimmed++;
            ans=min(ans,help(nums,k,i+1)+k+trimmed);
        }
        
        return dp[idx]=ans;
    }
    int minCost(vector<int>& nums, int k) {
        
        memset(dp,-1,sizeof(dp));
        return help(nums,k,0);
    }
};