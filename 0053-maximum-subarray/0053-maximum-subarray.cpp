class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int mx=nums[0],cursum=0;
        
        for(int i:nums){
            if(cursum<0) cursum=0;
            cursum+=i;
            mx=max(mx,cursum);
            
            
        }
        return mx;
    }
};