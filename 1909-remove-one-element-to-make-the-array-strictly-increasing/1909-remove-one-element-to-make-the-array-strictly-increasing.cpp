class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int canremove=-1,last=0;
        
        for(int i=0;i<nums.size();i++){
            
            if(canremove!=-1 and nums[i]<=last) return false;
            
            if(i>0 and nums[i]<=nums[i-1]){
                
                if(canremove!=-1) return false;
                if(i-2>=0 and nums[i]<=nums[i-2]){
                    last=nums[i-1];
                   canremove=nums[i]; 
                }
                
                else {canremove=nums[i-1];}
            }
        }
        
        return true;
    }
};