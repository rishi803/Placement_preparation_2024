class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        for(int i=0; i<nums.size(); i++){
            
            while(nums[i] >= 0 and nums[i] < nums.size() and nums[i] != i and nums[i] != nums[nums[i]]){
                swap(nums[i], nums[nums[i]]);
            }
            
        }
        
        for(int i=1; i<nums.size(); i++){
            if(nums[i] != i) return i;
        }
        
        return nums[0]!=nums.size() ? nums.size() : nums.size()+1;
    }
};