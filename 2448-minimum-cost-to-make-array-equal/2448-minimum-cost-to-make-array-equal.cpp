class Solution {
public:
    
    long costofall(vector<int>&nums,vector<int>&cost,long ele){
      
        long ans=0;
        
        for(int i=0;i<nums.size();i++){
            ans+=abs(nums[i]-ele)*cost[i];
        }
        return ans;
    }
    
    long long minCost(vector<int>& nums, vector<int>& cost) {
        
        long left=*min_element(nums.begin(),nums.end());
        long right=*max_element(nums.begin(),nums.end());
        long long ans=INT_MAX;
        
        while(left<right){
            long mid=(left+(right-left)/2);
            long leftans=costofall(nums,cost,mid);
            long rightans=costofall(nums,cost,mid+1);
            ans=min(leftans,rightans);
            
            if(leftans<rightans){
                right=mid;
            }
            else{
                left=mid+1;
            }
        }
        
        return ans==INT_MAX?0:ans;
    }
};