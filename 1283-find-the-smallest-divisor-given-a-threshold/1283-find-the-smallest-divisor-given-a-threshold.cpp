class Solution {
public:
    
    bool isvalid(vector<int>&nums, int mid, int threshold){
           int sum= 0;
        
        for(int i=0; i<nums.size(); i++){
            int times= nums[i] / mid;
            
            if(nums[i] % mid != 0) times++;
            
            sum+= times;
        }
        
        return sum <= threshold;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int low= 1;
        int high= *max_element(nums.begin(), nums.end());
        int ans= 0;
        
        while(low <= high){
            int mid= low + (high-low)/2;
            
            if(isvalid(nums,mid,threshold)){
                ans= mid;
                high= mid-1;
            }
            
            else{
                low= mid+1;
            }
        }
        
        return ans;
    }
};