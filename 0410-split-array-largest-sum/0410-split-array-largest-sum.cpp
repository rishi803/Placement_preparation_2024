class Solution {
public:
    
    bool isvalid(vector<int>&nums,int subarrays, int cansum){
        
        int sum= 0;
        int subarray= 1;
        
        for(int i=0; i<nums.size(); i++){
            sum+= nums[i];
            
            if(sum > cansum){
                sum= nums[i];
                subarray++;
            }
        }
        
        return subarray <= subarrays;
    }
    
    int splitArray(vector<int>& nums, int k) {
        
        int low=  *max_element(nums.begin(), nums.end());
        int high= accumulate(nums.begin(), nums.end(), 0);
        int ans= 0;
        
        while(low <= high){
            int mid= low+(high - low)/2;
            
            if(isvalid(nums,k,mid)){
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