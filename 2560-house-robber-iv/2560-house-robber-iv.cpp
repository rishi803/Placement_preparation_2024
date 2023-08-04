class Solution {
public:
    
    bool isvalid(vector<int>&nums, int k, int mid){
        
        int i=0;
        while(i < nums.size()){
            if(nums[i]<=mid) k--, i+=2;
            else i++;
            
            if(k==0) return true;
        }
        
        return k==0;
    }
    
    int minCapability(vector<int>& nums, int k) {
        
        int low=  *min_element(nums.begin(),nums.end());
        int high= *max_element(nums.begin(),nums.end());
        
        int ans=-1;
        
        while(low <= high){
            int mid= low + (high-low)/2;
            
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