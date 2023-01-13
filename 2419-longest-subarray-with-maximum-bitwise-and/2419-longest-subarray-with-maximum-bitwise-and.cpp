class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx=*max_element(nums.begin(),nums.end());
        int cnt=1,max_ans=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==mx and nums[i] ==nums[i-1]){
            cnt++;
            }
            
            else cnt=1;        // ex: [3,3,2,3,3,3]
            
            max_ans=max(max_ans,cnt);
            
        }
        return max_ans;
    }
};