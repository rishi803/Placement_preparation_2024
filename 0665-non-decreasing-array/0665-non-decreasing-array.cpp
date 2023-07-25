class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        
        bool flag=false;
        
        for(int i=1;i<nums.size();i++){
           if(nums[i]<nums[i-1]){
               if(flag==true) return false;
               
               if(i>1 and nums[i]<nums[i-2]) nums[i]=nums[i-1],flag=true;
               else if(i==1 or nums[i]>=nums[i-2]) nums[i-1]=nums[i],flag=true;
               
           }
        }
        return true;
    }
};