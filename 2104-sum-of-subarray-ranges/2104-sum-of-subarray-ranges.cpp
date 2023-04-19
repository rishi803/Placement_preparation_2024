class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        
        long long ans=0;
        
        for(int i=0;i<nums.size();i++){
            
            int large=nums[i],sm=nums[i];
            
            for(int j=i+1;j<nums.size();j++){
                large=max(large,nums[j]);
                sm=min(sm,nums[j]);
                
                ans+=(large-sm);
            }
        }
        
        return ans;
    }
};