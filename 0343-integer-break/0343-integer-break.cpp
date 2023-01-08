class Solution {
public:
    int counter3=3;
    int help(int n){
        if(n==2) return 1;
        if(n==3) return 2;
        if(n==4) return 4;
        if(n==5) return 6;
        if(n==6) return 9;
        int prev=9,prev2=6,ans=prev+prev2;
        
        for(int i=7;i<=n;i++){
            if(i%3==0){
                
                ans=prev2+prev-counter3;
                   counter3*=3;
              
            }
            else{
                ans=prev2+prev-counter3;
            }
            prev2=prev;
            prev=ans;
        }
        return ans;
        
    }
    int integerBreak(int n) {
        return help(n);
    }
};