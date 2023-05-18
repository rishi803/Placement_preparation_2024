class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
      vector<int>lis(nums.size(),1);
      vector<int>count(nums.size(),1);
      int ans=0,mx=1;
        
       for(int i=1;i<nums.size();i++){
           
           for(int j=0;j<i;j++){
                  
                  if(nums[i]>nums[j]){
                  if(lis[j]+1>lis[i]){
                      lis[i]=lis[j]+1;
                      count[i]=count[j];
                  }
                  else if(lis[j]+1==lis[i]){
                      count[i]+=count[j];
                  }
               }
           }
           mx=max(mx,lis[i]);
       } 
        
        for(int i=0;i<nums.size();i++){
            // cout<<count[i]<<endl;
            if(lis[i]==mx) ans+=count[i];
        }
        
          return ans;
    }
};