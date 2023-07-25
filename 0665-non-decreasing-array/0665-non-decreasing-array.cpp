class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        
        bool flag=false;
        
        for(int i=1;i<nums.size();i++){
           if(nums[i]<nums[i-1]){                  // means some case like--> 5 4
               
               if(flag==true) return false;        // already 1 change has made

               if(i>1 and nums[i]<nums[i-2]) {  // 1st case curr ele < prev ka prev
                   nums[i]=nums[i-1];          //   1 2 30 50 20    (20 is curr ele) so must increase 20 to 50
               }
               else if(i==1 or nums[i]>=nums[i-2]){ // 2nd case curr >= prev ka prev
                   nums[i-1]=nums[i];             // 1 2 30 50 40  (40 is curr ele) so must down 50 to 40
               } 
               flag=true;                 // we have made a change
           }
        }
        return true;
    }
};