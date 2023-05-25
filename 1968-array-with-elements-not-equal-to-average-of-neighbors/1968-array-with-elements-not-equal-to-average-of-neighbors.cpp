class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size()-1;i+=2){
            swap(nums[i],nums[i+1]);
        }
        // for(int i=0;i<nums.size();i++){
        //     swap(nums[i],nums[nums.size()-i-1]);
        // }
        return nums;
    }
};