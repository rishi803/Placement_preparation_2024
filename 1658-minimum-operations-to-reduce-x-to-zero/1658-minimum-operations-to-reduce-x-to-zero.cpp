class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int reqsum=sum-x;
        if(reqsum==0) return nums.size();
        if(reqsum<0) return -1;                     // for [1,1] and 3
        int head=0,tail=0,mxlen=0,mysum=0;
        for(head=0;head<nums.size();head++){
            mysum+=nums[head];
            while(mysum>reqsum){
                mysum-=nums[tail];
                tail++;
            }
            if(mysum==reqsum){
                mxlen=max(mxlen,head-tail+1);
            }
        }
        return mxlen==0?-1:nums.size()-mxlen;
    }
};