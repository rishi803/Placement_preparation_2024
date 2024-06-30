class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int ans= 0;
        mp[0]= 1;
        int sum= 0;
        
        for(int i=0; i<nums.size(); i++){
            sum= sum+nums[i];
            
            if(mp[sum-k] >= 0) ans+=mp[sum-k];
            
            mp[sum]+=1;
        }
        
        return ans;
    }
};