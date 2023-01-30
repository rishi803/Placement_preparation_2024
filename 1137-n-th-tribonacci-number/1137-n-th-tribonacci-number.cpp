class Solution {
public:
    int tribonacci(int n) {
        int a=0,b=1,c=1,ans=0;
        if(n==0 or n==1) return n;
        if(n==2) return 1;
        
        else {
            for(int i=3;i<=n;i++){
              ans=a+b+c;
                a=b;
                b=c;
                c=ans;
                
            }
        }
        return ans;
    }
};