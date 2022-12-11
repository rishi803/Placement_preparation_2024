class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int head=0,tail=0,ans=0,result=0;
        for(head=0;head<nums.size();head++){
          
            while((ans&nums[head])>0){
                ans^=nums[tail];
                tail++;
            }
            ans|=nums[head];
            
            result=max(result,head-tail+1);
            
        }
        return result;
    }
};