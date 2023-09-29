class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool mi=false,md=false;
        bool increasing= true, decreasing= true;
        
        for(int i=1; i<nums.size(); i++){
         
            if(nums[i] >= nums[i-1]){
                mi= true;
            }
            else{
                increasing= false;
                break;
            }
        }
        
        if(increasing == true) return true;
        
         for(int i=1; i<nums.size(); i++){
         
            if(nums[i] <= nums[i-1]){
                if( decreasing==false ) return false;
                md= true;
            }
            else{
                decreasing= false;
            }
        }
        
        return decreasing;
    }
};