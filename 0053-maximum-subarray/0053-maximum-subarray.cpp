class Solution {
public:
    
    int mx=INT_MIN;
    int curr=0;
    int maxSubArray(vector<int>& nums) {
        
        for(int i=0;i<nums.size();i++){
            
            curr+=nums[i];
            mx=max(mx,curr);
            if(curr<0){
                curr=0;
            }
        }
        return mx;
    }
};