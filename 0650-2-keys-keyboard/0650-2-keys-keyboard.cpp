class Solution {
public:
    
   
    long long help(int n,long long value,long long copy){
        if(value>n) return INT_MAX;
        if(value==n) return 0;
        
     return  min(2+help(n,value+value,value),1+help(n,value+copy,copy));
        
        
        
    }
    
    int minSteps(int n) {
        if(n==1) return 0;
        if(n==2) return 2;
        return  1+help(n,1,1);
    }
};