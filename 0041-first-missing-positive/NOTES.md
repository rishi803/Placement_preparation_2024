https://leetcode.com/problems/first-missing-positive/discuss/767105/Short-C%2B%2B-O(n)-time-O(1)-space-oror-Steps-explained
​
**1. CYCLE SORT**
​
```
int firstMissingPositive(vector<int>& nums) {
int n=nums.size();
for(int i=0 ; i<n ; i++)
{
while(nums[i]>0 and nums[i]<=n and nums[i]!=nums[nums[i]-1])
swap(nums[i],nums[nums[i]-1]);
}
for(int i=0 ; i<n ; i++) if(nums[i] != i+1) return i+1;
return n+1;
}
```
Test cases
[1,1]         [2,1]        [1]     [2]