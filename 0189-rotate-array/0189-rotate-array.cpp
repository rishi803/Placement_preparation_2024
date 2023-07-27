class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int rotate_time= k % nums.size();
        
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + rotate_time);
        reverse(nums.begin()+rotate_time, nums.end());
        
      
    }
};