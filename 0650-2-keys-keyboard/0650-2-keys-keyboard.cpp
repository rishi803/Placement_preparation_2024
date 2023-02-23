class Solution {
public:
    
    long long help(int n, long long copy,long long value){
        
        if(value>n) return INT_MAX-2;
        if(value==n) return 0;
    
        long long  copy_paste=2+help(n,value,value+value);
        long long paste= 1+help(n,copy,value+copy);
        
        return min(copy_paste,paste);
        
    }
    
    int minSteps(int n) {
        
        if(n==1) return 0;
        return 2+help(n,1,2);
    }
};