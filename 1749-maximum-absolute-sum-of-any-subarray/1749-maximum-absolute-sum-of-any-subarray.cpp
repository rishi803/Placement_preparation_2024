class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int curneg=0,curpos=0,mx=nums[0],mn=nums[0];
        
        for(int i:nums){
            
            curpos+=i;
            curneg+=i;
            mx=max(mx,curpos);
            mn=min(mn,curneg);
            
            if(curpos<0) curpos=0;
            if(curneg>0) curneg=0;
        }
        
        return max(mx,-mn);
    }
};