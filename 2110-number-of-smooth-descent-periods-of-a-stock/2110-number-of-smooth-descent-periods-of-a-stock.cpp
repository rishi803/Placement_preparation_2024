// why not head-tail+1  (because i will directly add size at last all single elements)
// during execution if i add single occurence then how i know that which single element remains thats why
// this some good sliding window problems in which you have to apply by yourself

class Solution {
public:
    long long getDescentPeriods(vector<int>& nums) {
        
        long long head=0,tail=0,ans=0;
        
        for(head=1;head<nums.size();head++){
            
            
            while(head<nums.size() and nums[head]-nums[head-1]==-1)  ans+=(head-tail+1),head++;
            
            ans-=head-tail-1;
            tail=head;
        }
        
        return ans+nums.size();
    }
};