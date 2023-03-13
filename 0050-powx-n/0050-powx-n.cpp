class Solution {
public:
    
  
    double myPow(double x, long long n) {
        
          if(n==0) return 1;
        
      
        if(n<0){
            x=1/x;
            n=-n;
        }
        
        double ans=myPow(x,n/2);
        
         if(n%2==0) return ans*ans;
        
        else return x * ans * ans;
       
    }
};