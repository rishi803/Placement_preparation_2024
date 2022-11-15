class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
      vector<int>ans;
        ans.push_back(INT_MIN);
        for(int i=0;i<nums.size();i++){
            
            if(ans.size()>=4) return true;
            if(nums[i]>ans.back()) ans.push_back(nums[i]);
            else{
                auto idx=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[idx]=nums[i];
            }
           
        }
        if(ans.size()>=4) return true;
        else return false;
    }
};