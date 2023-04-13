class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
          long long head=0,tail=0,ans=0;
        
        for(head=0;head<nums.size();head++){
            
            tail=head;
            
            while(head<nums.size() and nums[head]==0){
                ans+=(head-tail+1);
                head++;
            }
            
        }
        
        return ans;
    }
};