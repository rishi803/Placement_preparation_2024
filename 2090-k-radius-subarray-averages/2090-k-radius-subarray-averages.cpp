class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int sz=nums.size();
      
        vector<int>ans(sz,-1);
          if(sz<2*k) return ans;
        long long presum=0;
        for(int i=0;i<2*k;i++) presum+=nums[i];
      
        int total=k+k+1;
        
        for(int i=k;i<sz-k;i++){
            presum+=nums[i+k];
              // cout<<presum<<endl;
            ans[i]=(presum/total);
            presum-=nums[i-k];
        }
        
        return ans;
    }
};