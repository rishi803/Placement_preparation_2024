class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        
        long long head=0,tail=0,ans=0,sum=0;
        
        for(head=0;head<nums.size();head++){
            sum+=nums[head];
            
            while(sum*(head-tail+1)>=k){
                
                sum-=nums[tail];
                tail++;
            }
            
            ans+=head-tail+1;
        }
        return ans;
    }
};