class Solution {
public:
    long long getDescentPeriods(vector<int>& nums) {
        
        long long head=0,tail=0,ans=0;
        
        for(head=0;head<nums.size();head++){
            
            while(head>0 and head<nums.size() and nums[head]-nums[head-1]==-1)  ans+=(head-tail),head++;
            
            tail=head;
        }
        
        return ans+nums.size();
    }
};