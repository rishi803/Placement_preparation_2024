class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        
        int curszofmap=1;
        unordered_map<int,int>mp;
        mp[nums[0]-0]=1;
        
        long long ans=0;
        
        for(int i=1;i<nums.size();i++){
            
            if(mp.find(nums[i]-i)!=mp.end()){
                // cout<<ans<<endl;
                ans+=curszofmap-mp[nums[i]-i];
            }
            
            else ans+=curszofmap;
            
            mp[nums[i]-i]++;
            curszofmap++;
            
        }
        
        return ans;
    }
};