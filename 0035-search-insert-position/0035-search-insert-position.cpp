class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int idx=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(idx>0 and nums[idx-1]==target) return idx-1;
        return idx;
    }
};