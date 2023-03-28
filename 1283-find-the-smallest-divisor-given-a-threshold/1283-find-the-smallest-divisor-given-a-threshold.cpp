class Solution {
public:
    
    bool isvalid(int mid,vector<int>&nums,int threshold){
        
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            
            cnt+=nums[i]/mid;
            
            if((nums[i]/mid)*mid!=nums[i]) cnt++;
        }
        return cnt<=threshold;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        sort(nums.begin(),nums.end());
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        
        int ans=-1;
        
        while(low<=high){
            
            int mid= low+(high-low)/2;
            if(isvalid(mid,nums,threshold)){
                ans=mid;
                high=mid-1;
            }
            
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};