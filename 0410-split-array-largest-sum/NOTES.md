**1. Binary Search**
​
```
class Solution {
public:
bool isValid(int mid_sum,vector<int>&nums,int k){
int cnt=1;
int sum=0;
for(int i=0;i<nums.size();i++){
sum+=nums[i];
if(sum>mid_sum){
cnt++;
sum=nums[i];
}
}
return cnt<=k;
}
int splitArray(vector<int>& nums, int k) {
int n=nums.size();
int ans=0;