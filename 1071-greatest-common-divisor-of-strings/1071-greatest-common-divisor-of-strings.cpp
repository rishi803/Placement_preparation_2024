class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string ans;
       int gcd=__gcd(str1.size(),str2.size());
        if(str1.size()<gcd or str2.size()<gcd) return "";
        for(int i=0;i<gcd;i++){
            if(str1[i]!=str2[i]) return "";
            ans+=str1[i];
        }
        string temp1,temp2;
        int a=str1.size()/gcd,b=str2.size()/(gcd);
       for(int i=0;i<a;i++) temp1+=ans;
        if(temp1!=str1) return "";
        for(int i=0;i<b;i++) temp2+=ans;
        if(temp2!=str2) return "";
       return ans;
    }
};