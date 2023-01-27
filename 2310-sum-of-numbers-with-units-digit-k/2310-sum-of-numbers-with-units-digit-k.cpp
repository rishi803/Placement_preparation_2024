class Solution {
public:
    int minimumNumbers(int num, int k) {
        if(num==0) return 0;
        if(num%10==0 and k==0) return 1;
      int mini=INT_MAX;  
        
        for(int i=k;i<=num;i+=10){
            int n=num-i;
            if(n%10==k) return 2;
            else{
                if(k>0 and n%k==0) mini=min(mini,n/k+1);
            }
            
        }
       return mini==INT_MAX?-1:mini;
    }
};