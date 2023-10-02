class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        
        unordered_map<int,int>mp;
        long long sum= 0, ans=0;
        
        for(int i=0; i<k; i++){
            sum+=nums[i];
            mp[nums[i]]++;
        }
        
        if(mp.size() >= m) ans=max(ans,sum);
        int tail= 0, head;
        
        for(head=k; head<nums.size(); head++){
            
            sum-=nums[tail];
            mp[nums[tail]]--;
            
            sum+=nums[head];
            mp[nums[head]]++;
            
            if(mp[nums[tail]] == 0) mp.erase(nums[tail]);
            
            if(mp.size() >= m) ans= max(ans, sum);
            
            tail++;
            
        }
        return ans;
    }
};