class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
       int head=0,tail=0,ans=0,prod=1;
        for(head=0;head<size(nums);head++){
            prod=prod*nums[head];
            while(prod>=k){
                prod=prod/nums[tail];
                tail++;
            }
            ans=ans+(head-tail+1);
        }
        return ans;
    }
};