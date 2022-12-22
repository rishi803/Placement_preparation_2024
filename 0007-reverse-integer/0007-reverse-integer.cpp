class Solution {
public:
    int reverse(int x) {
        long sign=1,num=0;
        if(x<0){
            string s=to_string(x);
            string t(s.begin()+1,s.end());
            x=stol(t);
            sign=-1;
        }
        while(x>0){
            num=num*10+(x%10);
                x/=10;
        }
        if(num>INT_MAX) return 0;
        return (num*sign);
    }
};