class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
       
        vector<int>temp;
        for(int i=0;i<nums.size();i++){
            if(!temp.empty() and temp.back()>=nums[i]){
                int idx=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[idx]=nums[i];
            }
            else temp.push_back(nums[i]);
        }
        return temp.size();
    }
};