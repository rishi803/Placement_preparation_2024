class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int sz= nums.size();
        
        vector<int>prefix(sz);
        vector<int>suffix(sz);
        
        prefix[0]= nums[0];
        suffix[sz-1]= nums[sz-1];
        
        for(int i=1; i<sz; i++){
            prefix[i]= max(prefix[i-1], nums[i]);
        }
        
        for(int i=sz-2; i>=0; i--){
            suffix[i]= max(suffix[i+1], nums[i]);
        }
        
        long long ans= 0;
        
        for(int j=1; j<sz-1; j++){
           
            long long result= (prefix[j-1] - nums[j]) * 1ll * suffix[j+1];
            ans= max(ans, result);
            
        }
        
        return ans;
    }
};