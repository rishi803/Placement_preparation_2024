class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1,-1};
        vector<int>ans;
        int idx=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int udx=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(idx<nums.size() and nums[idx]==target)ans.push_back(idx);
        else ans.push_back(-1);
        if(udx>0 and nums[udx-1]==target) ans.push_back(udx-1);
        else ans.push_back(-1);
        return ans;
    }
};