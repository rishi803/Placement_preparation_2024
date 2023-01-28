class Solution {
public:
    int atmost(vector<int>&nums,int goal){
        
        long sum=0,head=0,tail=0,ans=0;
        for(head=0;head<nums.size();head++){
            sum+=nums[head];
            
            while(sum>goal and tail<=head){
               
                sum-=nums[tail];
                tail++;
            }
             ans+=head-tail+1;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
       return atmost(nums,goal)-atmost(nums,goal-1);
    }
};