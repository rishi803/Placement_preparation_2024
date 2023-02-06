
// ex: nums = [2,5,1,3,4,7], n = 3  ---->   {3,2} {4,5} {7,1}
//  ( << 10 ) kiya kunki nums[i] ki range max 1000 hogi jo 10 bit me represent hoga

// 
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
    
           int len = nums.size();
        
        for(int i = n; i < len; i++) {
            nums[i] = (nums[i] << 10) | nums[i - n]; // 2 number store karo 
        }
        
        int index = 0;
        for(int i = n; i < len; i++, index += 2) {
            nums[index] = nums[i] & 1023;  // to extract 2nd number & with 1023 (all 10 bit set as 1)
            nums[index + 1] = nums[i] >> 10; // to get first number right shift by 10 ( >> 10)
        }
        
        return nums;
    }
};