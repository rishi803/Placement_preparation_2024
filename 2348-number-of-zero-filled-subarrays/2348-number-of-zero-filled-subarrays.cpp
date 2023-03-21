class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
      long long ans=0,head=0,tail=-1;
        
        for(head=0;head<nums.size();head++){
            
            if(nums[head]==0) ans+=head-tail;
            
            if(nums[head]!=0){
                tail=head;
            }
        }
        
        return ans;
    }
};