class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       
        if(nums.size()==1 and nums[0]!=0) return nums[0]==1?2:1;
        for(int i=0;i<nums.size();i++){
            
            while(nums[i]>0 and nums[i]<nums.size() and nums[i]!=nums[nums[i]] and i!=nums[i]){
                swap(nums[i],nums[nums[i]]);
            }
        }
        int mx=0;
        for(int i=0;i<nums.size();i++){
            if(i==0) mx=nums[0];
            if(i>0 and nums[i]!=i) return i;
        }
        
        return nums.size()==mx?mx+1:nums.size();
    }
};