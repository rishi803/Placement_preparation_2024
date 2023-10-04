class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        for(int i=0; i<nums.size(); i++){
            
            while(nums[i] != nums[nums[i]] ){
                swap(nums[i], nums[nums[i]]);
            }
        }
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != i) return nums[i];
        }
        
        return -1;
    }
};