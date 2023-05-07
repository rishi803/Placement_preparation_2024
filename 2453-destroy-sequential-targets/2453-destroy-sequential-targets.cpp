class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        sort(nums.begin(),nums.end());
        
        unordered_map<int,int>mp;
        
        for(auto i:nums){
            mp[i%space]++;
        }
        int mx=0;
        
        for(auto it:mp){
            mx=max(mx,it.second);
        }
        
        for(auto i:nums){
            if(mp[i%space]==mx) return i;
        }
        
        return -1;
    }
};