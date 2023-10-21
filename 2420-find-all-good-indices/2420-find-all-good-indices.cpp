class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int time) {
        
        int sz=nums.size();
        vector<int>pref(sz,1),suff(sz,1),ans;
      
        for(int i=sz-2;i>=0;i--){
            if(nums[i+1]<=nums[i]) pref[i]=pref[i+1]+1;
        }
        for(int i=1;i<sz;i++){
            if(nums[i]>=nums[i-1]) suff[i]=suff[i-1]+1;
        }
        for(int i=time;i<sz-time;i++){
          if(pref[i-time]>=time and suff[i+time]>=time) ans.push_back(i);
        }
        return ans; 
    }
};