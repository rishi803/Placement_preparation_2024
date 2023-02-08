**1. GREEDY **
​
```
class Solution {
public:
bool canJump(vector<int>& nums) {
int can_reach_upto=0;
for(int i=0;i<nums.size();i++){
can_reach_upto=max(can_reach_upto,nums[i]+i);
if(can_reach_upto==nums.size()-1) return true;
if(i>=can_reach_upto) return false;
}
return true;
}
};
```
​
**2. DP**
​
```
​
```
​