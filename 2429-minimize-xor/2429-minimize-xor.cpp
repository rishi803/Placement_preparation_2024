// try to as close as possible to num1

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt1=__builtin_popcount(num1);
        int cnt2=__builtin_popcount(num2);
        
        // case 1
        if(cnt1==cnt2) return num1;
        
        // case 2
        
        else if(cnt1>cnt2){                          // try to unset the bit in num1 at rightmost (remember n & (n-1))
            while(cnt1!=cnt2){
                num1=num1&(num1-1);
                cnt1--;
            }
            return num1;
        }
        
        // case 3 
         
        else {         // set the bit in num1 at rightmost place where its digit is already 0
            for(int i=0;i<31;i++){
              
                if((num1&(1<<i))==0){
                    num1=num1|(1<<i);
                    cnt1++;
                }
                 if(cnt1==cnt2) return num1;
            }
           
        }
        return 0;
    }
};