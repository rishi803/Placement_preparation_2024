class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mn=min_element(nums.begin(),nums.end())-nums.begin();
        int mx=max_element(nums.begin(),nums.end())-nums.begin();
        int sz=nums.size();
       return min({1+max(mn,mx), (sz-min(mn,mx)), 1+min(mn, mx) + (sz-max(mx, mn))});
    }
};