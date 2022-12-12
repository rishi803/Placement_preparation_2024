class Solution {
public:
    int climbStairs(int n) {
       int last=1,seclast=0,ans=0;
        for(int i=1;i<=n;i++){
            ans=last+seclast;
            seclast=last;
            last=ans;
        }
        return ans;
    }
};