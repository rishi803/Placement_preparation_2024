class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return 0;
        int temp=0;
        int ans = 0;
        
       for(int i=n-1;i>=2;i--){
           if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
               temp=1+temp;
               ans+=temp;
           }
           else temp=0;
       }
        
        return ans;
    }
};