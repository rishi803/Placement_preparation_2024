class Solution {
public:
   // Binary Search Approach
int singleNonDuplicate(vector<int>& nums) {
    int start = 0;
    int end = nums.size()-1;
    
    
    while(start<=end and nums.size()>1){     
        int mid = start + (end - start)/2;
        
        if(nums[mid] == nums[mid^1])
            start = mid + 1;
        else
            end = mid - 1;
    }
    
    return nums[start];
}
};