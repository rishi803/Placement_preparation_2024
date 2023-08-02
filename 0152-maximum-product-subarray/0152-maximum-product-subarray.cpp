// GOAL-->   upto  current element find max and min product and also check whther max product and min product start from current or continues from previous

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0],mx=1,mn=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0) swap(mn,mx);
            mn=min(nums[i],nums[i]*mn); // at current pos check whther we get min from previous element(means subarrays continues or subarray  will start from this current element)
            
            mx=max(nums[i],nums[i]*mx);
            // cout<<"mx"<<" "<<mx<<endl;
            ans=max(mx,ans);
            // cout<<i<<"ans"<<" "<<ans<<endl;
        }
        return ans;
    }
};