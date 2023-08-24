class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int mx=1, mn=1, ans= INT_MIN;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] < 0){
                swap(mx, mn);
            }
            
            mx= max(nums[i], mx*nums[i]);
            mn= min(nums[i], mn*nums[i]);
            
            ans= max(ans, mx);
        }
        
        return ans;
    }
};