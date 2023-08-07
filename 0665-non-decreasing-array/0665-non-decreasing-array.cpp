class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        
        bool modification= false;
        
        for(int i=0; i<nums.size(); i++){
            
            if(i>=1){
                 if(nums[i] < nums[i-1]){
                     
                     if(modification) return false;
                     
                     if(i-2 >= 0 and nums[i] >= nums[i-2]){
                         nums[i-1]= nums[i];
                         modification=true;
                     }
                     else if(i-2>=0){
                         nums[i]=nums[i-1];
                         modification=true;
                     }
                     else{
                         nums[i-1]= nums[i];
                         modification= true;
                     }
            }
            }
           
        }
        
        return true;
    }
};