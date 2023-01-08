class Solution {
public:
    
      bool dfs(vector<int> & nums,int curr_sum,int idx,int t,vector<bool> & vis,int k)
    {
        if(k==1)
            return true;
        if(idx>=nums.size())
            return false;
        if(curr_sum==t)
            return dfs(nums,0,0,t,vis,k-1);
        for(int i=idx;i<nums.size();i++)
        {
            if(vis[i]||curr_sum+nums[i]>t)
                continue;
            vis[i]=true;
            if(dfs(nums,curr_sum+nums[i],i+1,t,vis,k))
                return true;
            vis[i]=false;
        }
        return false;
        
    }
    bool canPartitionKSubsets(vector<int>& nums, int k)
    {
        vector<bool> vis(nums.size(),false);
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(nums.size()<k||sum%k!=0)
            return false;
        
        return dfs(nums,0,0,sum/k,vis,k);
        
    }
};