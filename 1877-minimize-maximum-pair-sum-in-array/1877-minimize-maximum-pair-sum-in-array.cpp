class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int mx=0;
        for(int i=0;i<=nums.size()/2;i++){
            mx=max(mx,nums[i]+nums[nums.size()-i-1]);
        }
        return mx;
    }
};