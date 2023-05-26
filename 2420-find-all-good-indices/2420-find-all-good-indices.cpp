// very much similar to https://leetcode.com/problems/find-good-days-to-rob-the-bank/

class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int time) {
         int sz=nums.size();
        vector<int>pref(sz,1),suff(sz,1),ans;
      
        for(int i=sz-2;i>=0;i--){
            if(nums[i]<=nums[i+1]) suff[i]=suff[i+1]+1;
        }
        for(int i=1;i<sz;i++){
            if(nums[i]<=nums[i-1]) pref[i]=pref[i-1]+1;
        }
        for(int i=time;i<sz-time;i++){
          if(pref[i-1]>=time and suff[i+1]>=time) ans.push_back(i);
        }
        return ans; 
    }
};