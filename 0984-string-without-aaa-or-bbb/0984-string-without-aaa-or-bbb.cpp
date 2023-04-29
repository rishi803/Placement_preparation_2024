class Solution {
public:
   string strWithout3a3b(int A, int B) {
        string s;
        
        while (A && B) {
            if (A > B) {
                s += "aab";
                A-=2,B--;
                
            } else if (B > A) {
                s += "bba";
                B-=2,A--;
            
            } else {
                s += "ab";
                A--,B--;
            }
            
        }
        while (A--) s += "a";
        while (B--) s += "b";
        return s;
    }
};