class Solution {
public:
    
    double help( double num, long pow){
        
        if(pow == 0) return 1;
        
        double calculate_pow= help(num, pow/2);
        
        if( pow & 1){
            return num * calculate_pow * calculate_pow;
        }
        
        else{
            return calculate_pow * calculate_pow;
        }
    }
    
    double myPow(double x, int n) {
        
        long long m= n;
        
        if(n < 0){
            x = 1/x;
            m= -m;
        }
        return help(x,m);
    }
};