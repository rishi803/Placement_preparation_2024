class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        
        long long head=0,tail=-1,ans=0;
        
        for(head=0;head<nums.size();head++){
            
            while(head<nums.size() and nums[head]==0){
                ans+=(head-tail);
                head++;
            }
            tail=head;
        }
        
        return ans;
    }
};