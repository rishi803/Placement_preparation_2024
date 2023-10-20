class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
       
        int sz= nums.size();
        vector<int>prefix(sz);
        vector<int>suffix(sz);
        prefix[0]= 0;
        suffix[sz-1]= 0;
        
        for(int i=1; i<sz; i++){
            prefix[i]= max(prefix[i-1], nums[i-1]);
        }
        
        for(int i= sz-2; i>=0; i--){
            suffix[i]= max(suffix[i+1],nums[i+1]);
        }
        
        long long ans= 0;
        
        for(int i=0; i<nums.size(); i++){
             ans= max(ans, (prefix[i]-nums[i]) * 1ll*suffix[i]);
        }
        
        return ans;
        
    }
};