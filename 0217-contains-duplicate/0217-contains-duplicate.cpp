class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int sz=nums.size();
        sort(nums.begin(),nums.end());
       nums.erase(unique(nums.begin(),nums.end()),nums.end());
        cout<<nums.size();
       if(sz!=nums.size()) return true;
        else return false;
    }
};