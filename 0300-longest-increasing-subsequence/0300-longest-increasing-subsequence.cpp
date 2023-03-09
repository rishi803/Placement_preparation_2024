class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int>ans;
        
        for(int i=0;i<nums.size();i++){
            int idx=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
            
            if(!ans.empty() and idx<ans.size())
            {
            
            ans[idx]=nums[i];
            }
            else ans.push_back(nums[i]);
        }
        
        return ans.size();
    }
    
};