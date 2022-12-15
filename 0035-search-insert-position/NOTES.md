int fun(int sv,int lv,vector<int>&nums,int target){
int mid=sv+(lv-sv)/2;
while(sv<=lv){
if(nums[mid]==target) return mid;
else if(nums[mid]>target) return fun(sv,mid-1,nums,target);
else return fun(mid+1,lv,nums,target);
}
return sv;
}
int searchInsert(vector<int>& nums, int target) {
int ans= fun(0,nums.size()-1,nums,target);
return ans;
}