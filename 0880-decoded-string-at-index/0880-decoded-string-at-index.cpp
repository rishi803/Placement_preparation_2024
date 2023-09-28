class Solution {
public:
    string decodeAtIndex(string s, int k) {
        
        long sz=0;
        
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]>='0' and s[i]<='9'){
                sz*=(s[i]-'0');
            }
            
            else{
                sz++;
            }
        }
        
        for(int i=size(s)-1; i>=0; i--)
        {
            if(s[i]>='0' and s[i]<='9')
            {
                sz/=(s[i]-'0');
                k= k% sz;
            }
            else{
                if(k % sz == 0) return string(1, s[i]);
                sz--;
            }
        }
        
        return "kuchtoreturnkaro";
        
    }
};