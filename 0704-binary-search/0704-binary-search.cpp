class Solution {
public:
    int helper(int s,vector<int>&nums,int e,int target){
       
        while(s<=e){
             int mid=s+(e-s)/2;
            if(target==nums[mid]){
                return mid;
            }
            if(target<nums[mid]){
               e=mid-1;
            }
            else if(target>nums[mid]){
                s=mid+1;
            }
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
       int ans= helper(0,nums,nums.size()-1,target);
        return ans;
    }
};