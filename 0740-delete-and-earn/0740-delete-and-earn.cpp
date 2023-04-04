class Solution {
public:
    vector<int>mp;
    vector<int>dp;
    
    int help(vector<int>&mp,int idx){
        
        if(idx>=mp.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        
        int takethis=idx*mp[idx]+help(mp,idx+2);
        int nottake=help(mp,idx+1);
        
        
        // cout<<idx<<" "<<takethis<<" "<<nottake<<endl;
        
        return dp[idx]=max(takethis,nottake);
    }
    
    
    
    int deleteAndEarn(vector<int>& nums) {
    
     
      int sz=nums.size();
      int mx=*max_element(nums.begin(),nums.end());
      mp.resize(mx+1,0);
      for(int i:nums){
          mp[i]++;
          
      }
     int mxsz=mp.size();
     dp.resize(mxsz+1,-1);
     return help(mp,0);
        
    }
};