class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int mx= *max_element(nums.begin(),nums.end());
        int cnt=1,ans=0;
        
        for(int i=0;i<nums.size();i++){
            
            if(i>0 and nums[i]==nums[i-1] and nums[i]==mx) cnt++;
            else{
                cnt=1;
            }
            
            ans=max(ans,cnt);
        }
        return ans;
    }
};