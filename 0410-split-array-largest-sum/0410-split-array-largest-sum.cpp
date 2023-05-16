class Solution {
public:
    
    bool isValid(int mid_sum,vector<int>&nums,int k){
        
        int cnt=1;
        int sum=0;
        
        for(int i=0;i<nums.size();i++){
          
            sum+=nums[i];
            
            if(sum>mid_sum){
           
                cnt++;
                sum=nums[i];
               
            }
        }
        return cnt<=k;
    }
    
    int splitArray(vector<int>& nums, int k) {
        
        int n=nums.size();
        int ans=0;
        
        int low=*max_element(nums.begin(),nums.end());
        int high= accumulate(nums.begin(),nums.end(),0);
        
        while(low<=high){
            
            int mid_sum=low+(high-low)/2;
            
            if(isValid(mid_sum,nums,k)){
                ans=mid_sum;
                 high=mid_sum-1;
            }
            
            else{
              low=mid_sum+1;
            }
        }
        
        return low;
    }
};