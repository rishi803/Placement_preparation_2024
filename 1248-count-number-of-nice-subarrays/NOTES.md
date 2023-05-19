class Solution {
public:
int numberOfSubarrays(vector<int>& nums, int k) {
return atMost(nums, k) - atMost(nums, k - 1);
}
int atMost(vector<int> &nums, int k) {
int head=0,tail=0,ans=0;
for(head=0;head<nums.size();head++){
if(nums[head]%2!=0){
k--;
}
while(k<0){
if(nums[tail]%2!=0) k++;
tail++;
}
ans+=head-tail+1;
}
return ans;
}
​
};