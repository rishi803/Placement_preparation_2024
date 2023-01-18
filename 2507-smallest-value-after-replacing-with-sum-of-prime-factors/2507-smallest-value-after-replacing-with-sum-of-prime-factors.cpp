class Solution {
public:
    int smallestValue(int n) {
      
        while(true){
             int sum=0;
             int prime=2,cnt=0;
             int fix=n;
            while(n>1){
                if(n%prime==0) {
                     sum+=prime;
                    cnt++;
                    n/=prime;
                }
                
                else prime++;
            }
            if(sum==fix) return fix;
            n=sum;
            // if(cnt<2) return n;
        }
        return -1;
    }
    
};